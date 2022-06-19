#include <iostream>
#include <Display.hpp>
#include <Platform.hpp>

Display::Display(SDL_Surface* tileset) {
    _tileset = tileset;

    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError()  << std::endl;
    } else {
        _window = SDL_CreateWindow("ZOGUE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Platform::SCREEN_WIDTH, Platform::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (_window == NULL) {
            std::cout << "Window could not be created! DL_Error: %s\n" << SDL_GetError() << std::endl;
        } else {
            //Get window surface
            _screenSurface = SDL_GetWindowSurface(_window);
            
            //Update the surface
            SDL_UpdateWindowSurface(_window);
        }
    }
};

Display::~Display() {
    //Destroy window
    SDL_DestroyWindow(_window);

    //Quit SDL subsystems
    SDL_Quit();
}

void Display::updateWindow() {
    SDL_UpdateWindowSurface(_window);
}

void Display::draw() {
    SDL_BlitSurface(_tileset, NULL, _screenSurface, NULL);
    updateWindow();
};
