#pragma once
#include <SDL.h>

class Display {
    public:
        Display(SDL_Surface* tileset);
        ~Display();
        // wrapper for SDL update window func
        void updateWindow();
        // temp draw func
        void draw();

    private:
        SDL_Window* _window = NULL;
        SDL_Surface* _screenSurface = NULL;
        SDL_Surface* _tileset = NULL;
};
