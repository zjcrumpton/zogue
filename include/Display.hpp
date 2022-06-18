#pragma once
#include <SDL.h>

class Display {
    public:
        Display();
        ~Display();

    private:
        SDL_Window* _window = NULL;
        SDL_Surface* _screenSurface = NULL;
};
