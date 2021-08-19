#include "State.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

State::State()//:bg()
{
    State::quitRequested = false;
}

void State::LoadAssets(){

}

void State::Update(float dt){
    if (SDL_QuitRequested()){
        quitRequested = true;
    }
}

void State::Render(){
    
}

bool State::QuitRequested(){return quitRequested;}