#include "sdlScreenHandler.h"

SdlHandler::SdlHandler(usho width, usho height, std::vector<std::vector<Color>>& screenRef) :
    _height(height), _width(width), _screenRef(screenRef)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw GeneralException("Failed to initialize SDL");
    }

    _window = SDL_CreateWindow("Renderer",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        _width, _height, SDL_WINDOW_SHOWN);

    if (!_window) {
        throw GeneralException("Failed to create SDL Window");
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer) {
        throw GeneralException("Failed to create SDL Renderer");
    }
}

SdlHandler::~SdlHandler() {
    if (_renderer) SDL_DestroyRenderer(_renderer);
    if (_window) SDL_DestroyWindow(_window);
    SDL_Quit();
}

void SdlHandler::updateScreen()
{
    // set the painter to black
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    // Clear the screen with the current draw color (black)
    SDL_RenderClear(_renderer);

    for (usho y = 0; y < _height; ++y) {
        for (usho x = 0; x < _width; ++x) {
            Color& pixel = _screenRef[y][x];
            // Set the draw color to the pixel's RGBA values
            SDL_SetRenderDrawColor(_renderer, pixel.r, pixel.g, pixel.b, pixel.a);
            // Draw the pixel at (x, y)
            SDL_RenderDrawPoint(_renderer, x, y);
        }
    }

    // Present the updated renderer to the screen
    SDL_RenderPresent(_renderer);
}
