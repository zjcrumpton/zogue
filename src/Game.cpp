#include <Game.hpp>
#include <SDL.h>
#include <iostream>
#include <Keys.hpp>

const char* TILESHEET_PATH = "assets/zogue.bmp";

Game::Game() {
    loadTileset();
    _display = new Display(_tileset);
    _display->draw();
};

Game::~Game() {
    delete _display;
    //Deallocate surface
    SDL_FreeSurface(_tileset);
    _tileset = NULL;
}

void Game::start() {
    while (_continue) { 
        handleInput();
    }
};

// load the tileset once and pass it around to be sliced instead of reloading
void Game::loadTileset() {
    _tileset = SDL_LoadBMP(TILESHEET_PATH);
    if (_tileset == NULL) {
        std::cout << "Unable to load image %s! SDL Error: %s\n" << TILESHEET_PATH << SDL_GetError() << std::endl;
        throw new std::runtime_error("Unable to load image!");
    }
}

void Game::quit() {
    _continue = false;
};

void Game::handleInput() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        Key gameKey = keymap[SDL_EventType(event.type)];
        switch (gameKey) {
            case Key::QUIT:
                quit();
                break;
        }
    }
};
