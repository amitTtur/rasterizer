#include "sdlScreenHandler.h"

SdlHandler::SdlHandler(int w, int h) : width(w), height(h) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw GeneralException(SDL_GetError());
    }

    window = SDL_CreateWindow("SDL2 Buffer Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_SHOWN);
    if (!window) throw GeneralException(SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) throw GeneralException(SDL_GetError());

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
        width, height);
    if (!texture) throw GeneralException(SDL_GetError());

    screenBuffer = new uint32_t[width * height](); // cleared buffer
}

SdlHandler::~SdlHandler() {
    delete[] screenBuffer;
    if (texture) SDL_DestroyTexture(texture);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void SdlHandler::updateScreen() {
    SDL_UpdateTexture(texture, nullptr, screenBuffer, width * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

uint32_t* SdlHandler::getBuffer() {
    return screenBuffer;
}

int SdlHandler::getWidth() const {
    return width;
}

int SdlHandler::getHeight() const {
    return height;
}
