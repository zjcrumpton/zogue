#pragma once
#include <SDL.h>
#include <unordered_map>

// Engine specific key event names to be mapped to native/SDL input events
// so that input can be interacted with at a higher level
typedef enum {
    UP = 1,
    DOWN,
    LEFT,
    RIGHT,
} Key;


// Engine specific keys mapped to SDL events
std::unordered_map<int, Key> keymap = {
    {SDLK_UP, Key::UP},
    {SDLK_w, Key::UP},
    {SDLK_DOWN, Key::DOWN},
    {SDLK_s, Key::DOWN},
    {SDLK_LEFT, Key::LEFT},
    {SDLK_a, Key::LEFT},
    {SDLK_RIGHT, Key::RIGHT},
    {SDLK_d, Key::RIGHT},
};
