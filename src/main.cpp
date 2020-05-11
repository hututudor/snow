#include "infrastructure/World.h"

int main(int argc, char* argv[]) {
  snow::World::init();
  snow::World::start();
  snow::World::destroy();
  return 0;
}