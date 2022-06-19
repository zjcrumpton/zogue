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
extern std::unordered_map<int, Key> keymap;
