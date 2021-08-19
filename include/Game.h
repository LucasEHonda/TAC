#ifndef GAME_H_
#define GAME_H_

#include "State.h"
#include <SDL2/SDL.h>
#include <string>
class Game{
    private:
        Game(std::string title, int width, int height);
        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;
    public:
        ~Game();
        void Run();
        SDL_Renderer* GetRenderer();
        State& GetState();
        static Game& GetInstance();
};

#endif