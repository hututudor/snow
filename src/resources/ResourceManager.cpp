#include "ResourceManager.h"

#include <fstream>
#include <iostream>
#include "../lua/Lua.h"

std::string snow::ResourceManager::m_path;
std::map<std::string, snow::Texture *> snow::ResourceManager::m_textures;

void snow::ResourceManager::load() {
  loadPath();

  sol::state index = Lua::loadIndex(m_path);
  sol::optional<sol::table> texturesExists = index["textures"];

  if (texturesExists != sol::nullopt) {
    sol::table textures = index["textures"];

    for (auto &it: textures) {
      std::string name = it.first.as<std::string>();
      std::string path = it.second.as<std::string>();
      m_textures[name] = new Texture(m_path + path);
    }
  }
}

void snow::ResourceManager::loadPath() {
  std::ifstream pathFile("./path.snow");

  if (!pathFile.is_open()) {
    m_path = "./";
    return;
  }

  std::getline(pathFile, m_path);
}

void snow::ResourceManager::destroy() {
  for (auto &it: m_textures) {
    it.second->unload();
    delete it.second;
  }
}

snow::Texture *snow::ResourceManager::getTexture(const std::string &name) {
  return m_textures[name];
}

std::string snow::ResourceManager::getPath() {
  return m_path;
}
