#include <iostream>
#include <Display.hpp>
#include <SDL.h>
#include <Platform.hpp>

Display::Display(char* tilesheetPath) {
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

    _tileset = SDL_LoadBMP(tilesheetPath);
    if (_tileset == NULL) {
        std::cout << "Unable to load image %s! SDL Error: %s\n" << tilesheetPath << SDL_GetError() << std::endl;
        throw new std::runtime_error("Unable to load image!");
    }

    // convert tileset bits
    _tileset = SDL_ConvertSurface(_tileset, _screenSurface->format, 0 );
    if (_tileset == NULL) {
        std::cout << "Unable to optimize tilesheet %s! SDL Error: %s\n" << SDL_GetError() << std::endl;
        throw new std::runtime_error("Unable to optimize image!");
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
