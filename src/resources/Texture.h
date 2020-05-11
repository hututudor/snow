#pragma once

#include <SDL.h>
#include <string>

namespace snow {
  class Texture {
  public:
    Texture(const std::string &path);
    ~Texture();

    void load();
    void unload();

    SDL_Texture *getTexture();

    int getWidth();
    int getHeight();
    SDL_Rect getSourceRect();

    bool isLoaded() const;
    const std::string &getPath() const;

  private:
    SDL_Texture *m_texture;
    bool m_isLoaded;
    std::string m_path;
  };
}

