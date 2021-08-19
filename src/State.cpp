#include "State.h"

State::State(){
    State::quitRequested = false;
    State::bg = new Sprite();
}

void State::LoadAssets(){

}

void State::Update(float dt){
    if (SDL_QuitRequested()){
        State::quitRequested = true;
    }
}

void State::Render(){
    
}

bool QuitRequested(){
    
}