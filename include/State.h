#ifndef STATE_H_
#define STATE_H_

#include "Sprite.h"
#include "Music.h"
#include "GameObject.h"
#include <vector>
class State{
    private:
        Sprite bg;
        Music music;
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectArray;
    public:
        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
        void Input();
        void AddObject(int mouseX, int mouseY);
};

#endif