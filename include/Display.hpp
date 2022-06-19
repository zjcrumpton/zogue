#pragma once
#include <SDL.h>

class Display {
    public:
        Display(char* tilesheetPath);
        ~Display();
        // wrapper for SDL update window func
        void updateWindow();
        // temp draw func
        void draw();

        // getters
        SDL_Surface* tileset();

    private:
        SDL_Window* _window = NULL;
        SDL_Surface* _screenSurface = NULL;
        SDL_Surface* _tileset = NULL;
};
