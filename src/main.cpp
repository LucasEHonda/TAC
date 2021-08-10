#include <iostream>

#include "Game.h"

using namespace std;

int main (int argc, char** argv){
    Game jogo = Game::GetInstance();
    SDL_Delay(5000);
    return 0;
}