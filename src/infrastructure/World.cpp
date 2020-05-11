#include "World.h"
#include "../resources/ResourceManager.h"
#include "../resources/Preferences.h"
#include "Renderer.h"
#include "../Config.h"

#include <iostream>

bool snow::World::m_isRunning;
SDL_Window *snow::World::m_window;
SDL_Renderer *snow::World::m_renderer;
int snow::World::m_ticksLastFrame;
SDL_Event snow::World::m_event;
int snow::World::m_startTime;
SDL_Rect snow::World::m_splashRect;
SDL_Rect snow::World::m_sourceRect;

void snow::World::init() {
  m_isRunning = false;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL" << std::endl;
    exit(-1);
  }

  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    std::cerr << "Error initializing IMG" << std::endl;
    exit(-1);
  }

  ResourceManager::load();
  Preferences::load();

  int width = Preferences::get<int>("width", WIDTH);
  int height = Preferences::get<int>("height", HEIGHT);
  auto title = Preferences::get<std::string>("title", "snow engine");

  unsigned int windowHints = 0;
  windowHints |= (Preferences::get<bool>("fullscreen", false) ? SDL_WINDOW_FULLSCREEN : 0);

  m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                              windowHints);
  if (!m_window) {
    std::cerr << "Error creating SDL window" << std::endl;
    exit(-1);
  }

  m_renderer = SDL_CreateRenderer(m_window, -1, 0);
  if (!m_renderer) {
    std::cerr << "Error creating SDL renderer" << std::endl;
    exit(-1);
  }

  std::string iconPath = ResourceManager::getTexture(Preferences::get<std::string>("icon", "splash"))->getPath();
  SDL_Surface *surface = IMG_Load(iconPath.c_str());
  SDL_SetWindowIcon(m_window, surface);
  SDL_FreeSurface(surface);
}

void snow::World::destroy() {
  ResourceManager::destroy();

  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void snow::World::start() {
  m_isRunning = true;
  m_ticksLastFrame = SDL_GetTicks();
  m_startTime = SDL_GetTicks();

  snow::ResourceManager::getTexture("splash")->load();

  m_sourceRect = snow::ResourceManager::getTexture("splash")->getSourceRect();
  m_splashRect.x =
    Preferences::get<int>("width", WIDTH) / 2 - snow::ResourceManager::getTexture("splash")->getWidth() / 2;
  m_splashRect.y =
    Preferences::get<int>("height", HEIGHT) / 2 - snow::ResourceManager::getTexture("splash")->getHeight() / 2;
  m_splashRect.w = snow::ResourceManager::getTexture("splash")->getWidth();
  m_splashRect.h = snow::ResourceManager::getTexture("splash")->getHeight();

  while (m_isRunning) {
    processInput();
    update();
    render();
  }
}

void snow::World::processInput() {
  SDL_PollEvent(&m_event);
  switch (m_event.type) {
    case SDL_QUIT: {
      m_isRunning = false;
      break;
    }

    default: {
      break;
    }
  }
}

void snow::World::update() {
  static float FRAME_TARGET_TIME = 1000.0f / Preferences::get<int>("fps", FPS);

  while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticksLastFrame + FRAME_TARGET_TIME));
  float deltaTime = (SDL_GetTicks() - m_ticksLastFrame) / 1000.0f;
  deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;
  m_ticksLastFrame = SDL_GetTicks();
}

void snow::World::render() {
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
  SDL_RenderClear(m_renderer);

  if (m_startTime + LOGO_TIME >= SDL_GetTicks()) {
    SDL_SetRenderDrawColor(m_renderer, 100, 100, 100, 255);
    SDL_RenderClear(m_renderer);
    snow::Renderer::drawTexture("splash", &m_sourceRect, &m_splashRect, (SDL_GetTicks() / 10) % 360);
  } else {

  }

  SDL_RenderPresent(m_renderer);
}

SDL_Renderer *snow::World::getRenderer() {
  return m_renderer;
}
