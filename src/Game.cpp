#include "Game.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

Game* Game::instance = nullptr;

Game::Game(std::string title, int width, int height){}

Game& Game::GetInstance(){
    if (instance == nullptr){
        instance = new Game("Lucas Honda 180105281", 1024, 600);
    }
    return *instance;
}