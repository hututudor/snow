#pragma once

#include "../../deps/sol/sol.hpp"

namespace snow {
  class Lua {
  public:
    static sol::state loadIndex(const std::string &path);
    static sol::state loadPreferences(const std::string &path);
  };
}