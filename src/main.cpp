#include <iostream>

#include "Game.h"

using namespace std;

int main (int argc, char** argv){
    Game jogo = Game::GetInstance();
    jogo.Run();
    return 0;
}