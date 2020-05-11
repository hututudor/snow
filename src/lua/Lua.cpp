#include "Lua.h"

sol::state snow::Lua::loadIndex(const std::string &path) {
  sol::state lua;
  lua.open_libraries(sol::lib::base, sol::lib::os);
  lua.script_file(path + "index.snow");
  return lua;
}

sol::state snow::Lua::loadPreferences(const std::string &path) {
  sol::state lua;
  lua.open_libraries(sol::lib::base, sol::lib::os);
  lua.script_file(path + "config.snow");
  return lua;
}
