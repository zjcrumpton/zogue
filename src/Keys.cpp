#include <Keys.hpp>
#include <unordered_map>

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
