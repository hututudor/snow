#pragma once

#include "Texture.h"
#include <string>
#include <map>

namespace snow {
  class ResourceManager {
  public:
    static void load();
    static void destroy();

    static Texture* getTexture(const std::string& name);
    static std::string getPath();

  private:
    static std::string m_path;
    static std::map<std::string, Texture*> m_textures;

    static void loadPath();
  };
}
