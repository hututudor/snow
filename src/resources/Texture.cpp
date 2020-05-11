#include "Texture.h"

#include <SDL_image.h>
#include <iostream>
#include "../infrastructure/World.h"

snow::Texture::Texture(const std::string &path) {
  m_path = path;
  m_isLoaded = false;
}

snow::Texture::~Texture() {
  SDL_DestroyTexture(m_texture);
}

void snow::Texture::load() {
  if (!isLoaded()) {
    SDL_Surface *surface = IMG_Load(m_path.c_str());
    m_texture = SDL_CreateTextureFromSurface(snow::World::getRenderer(), surface);
    SDL_FreeSurface(surface);
    m_isLoaded = true;
  }
}

void snow::Texture::unload() {
  if (isLoaded()) {
    SDL_DestroyTexture(m_texture);
    m_isLoaded = false;
  }
}

SDL_Texture *snow::Texture::getTexture() {
  return m_texture;
}

bool snow::Texture::isLoaded() const {
  return m_isLoaded;
}

const std::string &snow::Texture::getPath() const {
  return m_path;
}

int snow::Texture::getWidth() {
  int w, h;
  SDL_QueryTexture(m_texture, nullptr, nullptr, &w, &h);
  return w;
}

int snow::Texture::getHeight() {
  int w, h;
  SDL_QueryTexture(m_texture, nullptr, nullptr, &w, &h);
  return h;
}

SDL_Rect snow::Texture::getSourceRect() {
  int w, h;
  SDL_QueryTexture(m_texture, nullptr, nullptr, &w, &h);

  SDL_Rect ret;
  ret.x = 0;
  ret.y = 0;
  ret.w = w;
  ret.h = h;

  return ret;
}
