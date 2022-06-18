#pragma once
#include <Display.hpp>

class Game {
public:
    Game();
    ~Game();
    // start the main game loop
    void start();
private:
    Display* _display;
};
