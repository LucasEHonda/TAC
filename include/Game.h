#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include <string>

class Game{
private:
    Game(std::string title, int width, int height);
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    // State* state;
public:
    ~Game();
    void Run();
    SDL_Renderer* GetRenderer();
    // State& GetState();
    static Game& GetInstance();
};

Game::Game(std::string title, int width, int height){
}

Game::~Game()
{
}

#endif