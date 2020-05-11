#include "Entity.h"

snow::Entity::Entity() {

}

snow::Entity::~Entity() {
  destroy();

  for (auto &it: m_components) {
    delete it;
  }

  m_components.clear();

  for (auto &it: m_componentTypeMap) {
    delete it.first;
    delete it.second;
  }

  m_componentTypeMap.clear();
}

void snow::Entity::start() {
  for (auto &it: m_components) {
    it->start();
  }
}

void snow::Entity::update() {
  for (auto &it: m_components) {
    it->update();
  }
}

void snow::Entity::render() {
  for (auto &it: m_components) {
    it->render();
  }
}

void snow::Entity::destroy() {
  for (auto &it: m_components) {
    it->destroy();
  }
}

const std::string &snow::Entity::getName() const {
  return m_name;
}

void snow::Entity::setName(const std::string &mName) {
  m_name = mName;
}

int snow::Entity::getLayer() const {
  return m_layer;
}

void snow::Entity::setLayer(int mLayer) {
  m_layer = mLayer;
}
