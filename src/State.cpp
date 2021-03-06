#include "State.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

State::State():bg("assets/img/ocean.jpg"), music("assets/audio/stageState.ogg")
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
    bg.Render(0, 0);
}

bool State::QuitRequested(){return quitRequested;}