#ifndef MUSIC_H_
#define MUSIC_H_

#include <SDL2/SDL_mixer.h>
#include <string>

class Music{
    private:
        Mix_Music* music;
    public:
        Music();
        ~Music();
        Music(std::string file);
        void Play(int times = -1);
        void Stop(int msToStop = 1500);
        void Open(std::string file);
        bool IsOpen();
};

#endif