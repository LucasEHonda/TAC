#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "GameObject.h"

#include <string>

class Component{
    protected:
        GameObject& associated;
    public:
        Component(GameObject associated);
        virtual ~Component();
        void virtual Update(float dt);
        void virtual Render();
        bool virtual Is(std::string type);
};

#endif