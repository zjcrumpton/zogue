#pragma once
#include <SDL.h>
#include <unordered_map>

// Engine specific key event names to be mapped to native/SDL input events
// so that input can be interacted with at a higher level
typedef enum {
    QUIT = 1
} Key;

// Engine specific keys mapped to SDL events
std::unordered_map<int, Key> keymap = {
    {SDL_QUIT, Key::QUIT}
};
