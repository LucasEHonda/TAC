#include "Game.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

Game* Game::instance = nullptr;

Game::Game(std::string title, int width, int height){
    if(instance == nullptr){
        instance = this;    
    }else{
        exit(EXIT_FAILURE);
    }

    // inicializar sdl
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0){
        std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // inicializar sdl image
    int imgInit = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    if (IMG_Init(imgInit) != imgInit){
        std::cout << "IMG_Init failed: " << IMG_GetError() << std::endl;
        exit(1);
    }

    // inicializar Window
    window = SDL_CreateWindow("Lucas Honda 180105281", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(!window){
        std::cout << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        exit(1);
    }
    
    // inicializar render
    renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        std::cout << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
        exit(1);        
    }
    
    // inicializar sdl mix
    int mixInit = MIX_INIT_OGG;
    if((Mix_Init(mixInit)&mixInit) != mixInit){
        std::cout << "Mix_Init: "  <<  Mix_GetError() << std::endl;
    }
    
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
        std::cout << "Mix_OpenAudio: " << Mix_GetError() << std::endl;
        exit(1);
    }
    
    Mix_AllocateChannels(32);
    state = new State();
}

Game::~Game(){
    Mix_CloseAudio();
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

// singleton
Game& Game::GetInstance(){
    if (instance == nullptr){
        instance = new Game("Lucas Honda 180105281", 1024, 600);
    }
    return *instance;
}

State& Game::GetState(){
    return *state;    
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

void Game::Run(){
    while(!GetState().QuitRequested()){
        GetState().Update(10);
        GetState().Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}