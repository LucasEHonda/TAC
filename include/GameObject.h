#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Component.h"
#include "Rect.h"

#include <string>
#include <vector>

class GameObject{
    private:
        std::vector <Component*> components;
        bool isDead;
    public:
        GameObject();
        ~GameObject();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        Component* GetComponent(std::string type);
        Rect box();
};

#endif