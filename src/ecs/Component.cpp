#include "Component.h"

snow::Component::Component(Entity *entity) {
  m_entity = entity;
}

snow::Component::~Component() {
  delete m_entity;
}

void snow::Component::start() {

}

void snow::Component::update() {

}

void snow::Component::render() {

}

void snow::Component::destroy() {

}
