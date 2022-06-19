#pragma once
#include <Display.hpp>
#include <SDL.h>

class Game {
    public:
        Game();
        ~Game();
        // start the main game loop
        void start();
    private:
        Display* _display;
        SDL_Surface* _tileset = NULL;

        void loadTileset();
};
