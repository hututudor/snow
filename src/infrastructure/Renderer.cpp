#include <iostream>
#include "Renderer.h"

#include "../resources/ResourceManager.h"
#include "World.h"

void snow::Renderer::drawTexture(const std::string &texture, SDL_Rect *source, SDL_Rect *dest, double angle) {
  if (snow::ResourceManager::getTexture(texture)->isLoaded()) {
    SDL_RenderCopyEx(snow::World::getRenderer(), snow::ResourceManager::getTexture(texture)->getTexture(), source, dest,
                     angle,
                     nullptr, SDL_FLIP_NONE);
  }
}

void snow::Renderer::drawColor(SDL_Rect *dest, int r, int g, int b, int a) {
  SDL_GetRenderDrawColor(snow::World::getRenderer(), (Uint8 *) r, (Uint8 *) g, (Uint8 *) b, (Uint8 *) a);
  SDL_RenderDrawRect(snow::World::getRenderer(), dest);
}
