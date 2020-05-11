#pragma once

class Entity;

namespace snow {
  class Component {
  public:
    Component(Entity *entity);
    ~Component();

    virtual void start();
    virtual void update();
    virtual void render();
    virtual void destroy();

  private:
    Entity *m_entity;
  };
}
