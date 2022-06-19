#include <Game.hpp>
#include <iostream>

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
    // temp code to keep the window open
    bool isquit = false;
    SDL_Event event;
    while (!isquit) { 
        if (SDL_PollEvent( & event)) {
            if (event.type == SDL_QUIT) {
            isquit = true;
            }
        }
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
