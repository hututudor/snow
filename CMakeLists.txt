cmake_minimum_required(VERSION 3.16)
project(snow)

set(CMAKE_CXX_STANDARD 17)

add_library(lualib STATIC deps/lua/src/lutf8lib.c deps/lua/src/lapi.c deps/lua/src/lcode.c deps/lua/src/lctype.c deps/lua/src/ldebug.c deps/lua/src/ldo.c deps/lua/src/ldump.c deps/lua/src/lfunc.c deps/lua/src/lgc.c deps/lua/src/llex.c deps/lua/src/lmem.c deps/lua/src/lobject.c deps/lua/src/lopcodes.c deps/lua/src/lparser.c deps/lua/src/lstate.c deps/lua/src/lstring.c deps/lua/src/ltable.c deps/lua/src/ltm.c deps/lua/src/lundump.c deps/lua/src/lvm.c deps/lua/src/lzio.c deps/lua/src/lauxlib.c deps/lua/src/lbaselib.c deps/lua/src/lbitlib.c deps/lua/src/lcorolib.c deps/lua/src/ldblib.c deps/lua/src/liolib.c deps/lua/src/lmathlib.c deps/lua/src/loslib.c deps/lua/src/lstrlib.c deps/lua/src/ltablib.c deps/lua/src/loadlib.c deps/lua/src/linit.c)
set_target_properties(lualib PROPERTIES OUTPUT_NAME "lua")

include_directories(deps/sdl/include)
include_directories(deps/sdl_image/include)
include_directories(deps/lua/include)
include_directories(deps/glm)
include_directories(deps/sol)

link_directories(deps/sdl/lib/x86)
link_directories(deps/sdl_image/lib/x86)

add_executable(snow src/main.cpp src/infrastructure/World.cpp src/infrastructure/World.h src/Config.h src/lua/Lua.cpp src/lua/Lua.h src/lua/Lua.cpp src/lua/Lua.h src/resources/ResourceManager.cpp src/resources/ResourceManager.h src/resources/Texture.cpp src/resources/Texture.h src/infrastructure/Renderer.cpp src/infrastructure/Renderer.h src/ecs/Entity.cpp src/ecs/Entity.h src/ecs/Component.cpp src/ecs/Component.h src/resources/Preferences.cpp src/resources/Preferences.h)
target_link_libraries(snow SDL2main SDL2 SDL2_image lualib)