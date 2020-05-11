#pragma once

#include <SDL.h>
#include <SDL_image.h>

namespace snow {
  class World {
  public:
    static void init();
    static void start();
    static void destroy();

    static SDL_Renderer* getRenderer();

  private:
    static bool m_isRunning;
    static SDL_Window *m_window;
    static SDL_Renderer *m_renderer;
    static SDL_Event m_event;
    static int m_ticksLastFrame;
    static int m_startTime;
    static SDL_Rect m_splashRect;
    static SDL_Rect m_sourceRect;

    static void processInput();
    static void update();
    static void render();
  };
}