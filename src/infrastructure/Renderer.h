#pragma once

#include <string>
#include <SDL.h>

namespace snow {
  class Renderer {
  public:
    static void drawTexture(const std::string &texture, SDL_Rect *source, SDL_Rect *dest, double angle);
    static void drawColor(SDL_Rect *dest, int r, int g, int b, int a);
  };
}
