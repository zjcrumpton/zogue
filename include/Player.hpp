#pragma once
#include <SDL.h>

class Player {
    public:
        Player();
        ~Player();

    private:
        SDL_Surface* sprite = NULL;
};
