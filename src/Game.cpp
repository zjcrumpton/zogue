#include <Game.hpp>
#include <iostream>

Game::Game() {
    _display = new Display();
};

Game::~Game() {
    delete _display;
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