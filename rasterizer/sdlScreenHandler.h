#pragma once
#ifndef SDL_SCREEN_HANDLER
#define SDL_SCREEN_HANDLER

#include <SDL.h>
#include <cstdint>

#include <vector>

#include "GeneralException.hpp"
#include "defines.hpp"

class SdlHandler {
public:
    // once screen is set width and height are not changing
    // note it can change if i decide to add this feature in the future
    SdlHandler(usho width, usho height,std::vector<std::vector<Color>>& screenRef) :
        _width(width), _height(height), _screenRef(screenRef) {};
    ~SdlHandler() = default;

    void updateScreen();

private:
    const usho _width;
    const usho _height;
    std::vector<std::vector<Color>>& _screenRef;
};

#endif // SDL_SCREEN_HANDLER
