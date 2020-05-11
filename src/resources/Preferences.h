#pragma once

#include <sol.hpp>
#include <iostream>

namespace snow {
  class Preferences {
  public:
    static void load();

    template<typename T>
    static T get(std::string key, T defaultValue) {
      sol::optional<T> exists = m_state[key];

      if (exists == sol::nullopt) return defaultValue;
      else return m_state[key];
    }

  private:
    static sol::state m_state;
  };
}
