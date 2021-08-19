#ifndef STATE_H_
#define STATE_H_

class Game{
    private:
        Sprite bg;
        Music music;
        bool quitRequested;
    public:
        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
};

#endif