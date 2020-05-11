#include "Preferences.h"
#include "ResourceManager.h"
#include "../lua/Lua.h"

sol::state snow::Preferences::m_state;

void snow::Preferences::load() {
  m_state = Lua::loadPreferences(ResourceManager::getPath());
}
