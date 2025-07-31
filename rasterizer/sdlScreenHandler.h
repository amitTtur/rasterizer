#pragma once
#ifndef SDL_SCREEN_HANDLER
#define SDL_SCREEN_HANDLER

#include <SDL.h>
#include <cstdint>

#include "GeneralException.hpp"

class SdlHandler {
public:
    SdlHandler(int width, int height); // private constructor

    void updateScreen();
    uint32_t* getBuffer();
    int getWidth() const;
    int getHeight() const;

private:
   
    ~SdlHandler();
    SdlHandler(const SdlHandler&) = delete;
    SdlHandler& operator=(const SdlHandler&) = delete;

    int width;
    int height;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
    uint32_t* screenBuffer = nullptr;
};

#endif // SDL_SCREEN_HANDLER
