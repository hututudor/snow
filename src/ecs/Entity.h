#pragma once

#include "Component.h"
#include <vector>
#include <map>
#include <typeinfo>

namespace snow {
  class Entity {
  public:
    Entity();
    ~Entity();

    void start();
    void update();
    void render();
    void destroy();

    template<typename T>
    T &addComponent() {
      T *newComponent(new T(this));
      m_components.emplace_back(newComponent);
      m_componentTypeMap[&typeid(*newComponent)] = newComponent;
      return *newComponent;
    }

    template<typename T>
    bool hasComponent() const {
      return m_componentTypeMap.count(&typeid(T));
    }

    template<typename T>
    T *getComponent() {
      return static_cast<T *>(m_componentTypeMap[&typeid(T)]);
    }

    const std::string &getName() const;
    void setName(const std::string &mName);
    int getLayer() const;
    void setLayer(int mLayer);

  private:
    std::string m_name;
    int m_layer;

    std::vector<Component *> m_components;
    std::map<const std::type_info *, Component *> m_componentTypeMap;
  };
}
