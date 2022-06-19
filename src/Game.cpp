#include <Game.hpp>
#include <SDL.h>
#include <iostream>
#include <Keys.hpp>

const char* TILESHEET_PATH = "assets/zogue.bmp";

Game::Game() {
    _display = new Display((char*)TILESHEET_PATH);
    _display->draw();
};

Game::~Game() {
    delete _display;
    //Deallocate surface
    SDL_FreeSurface(_tileset);
    _tileset = NULL;
};

void Game::start() {
    while (_continue) { 
        handleInput();
    }
};

void Game::quit() {
    _continue = false;
};

void Game::handleInput() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit();
            return;
        } else if (event.type == SDL_KEYDOWN) {
            Key gameKey = keymap[event.key.keysym.sym];

            switch (gameKey) {
                case Key::LEFT:
                    std::cout << "KEY PRESSED: " << "LEFTTT" << std::endl;
                    break;
            }
        }
    }
};
