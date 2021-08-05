#include "Game.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

Game* Game::instance = nullptr;

Game::Game(std::string title, int width, int height){
    
    // inicializar sdl
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0){
        std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
    }
    
    // inicializar sdl image
    int imgInit = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    if (IMG_Init(imgInit) != imgInit){
        std::cout << "IMG_Init failed: " << IMG_GetError() << std::endl;
    }
    
    // inicializar sdl mix
    // int Mix_Init(int flags)
    // int Mix_OpenAudio(int frequency, Uint16 format, int channels, int chunksize)
    // int Mix_AllocateChannels(int numchans)

    // inicializar Window
    SDL_Window *window = SDL_CreateWindow("Lucas Honda 180105281", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(!window){
        std::cout << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
    }
    
    // inicializar render
    SDL_Renderer *render =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!render){
        std::cout << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
    }


}

// singleton
Game& Game::GetInstance(){
    if (instance == nullptr){
        instance = new Game("Lucas Honda 180105281", 1024, 600);
    }
    return *instance;
}