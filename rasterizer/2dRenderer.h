#pragma once
#ifndef D2_RENDERER
#define D2_RENDERER

// misc includes
#include <vector>
#include <memory>
#include "sdlScreenHandler.h"
#include "Menu.h"

// object includes
#include "Triangle.h"

class D2_renderer
{
public:
	D2_renderer(const int screenWidth, const int screenHeight);
	~D2_renderer() = default;

	void addShape(std::unique_ptr<Object> toAdd);

private:
	std::vector<std::unique_ptr<Object>> _renderList;
	SdlHandler _sdlHandler;
	bool _listChanged;
	std::vector<std::vector<Color>> _screen;
};


#endif // !2D_RENDERER
