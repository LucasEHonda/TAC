#include "Music.h"

#include <iostream>

Music::Music(){
    music = nullptr;
}

Music::Music(std::string file){
    Open(file);
}

Music::~Music(){
    Stop();
    Mix_FreeMusic(music);
}

void Music::Play(int times){
    if(music){Mix_PlayMusic(music, times);}
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
    music = Mix_LoadMUS(file.c_str());
    if(!music){
        std::cout << "Mix_LoadMUS failed: " << Mix_GetError() << std::endl;
    }
    Play();
}

bool Music::IsOpen(){
    if(music){
        return 1;
    }
    return 0;
}
