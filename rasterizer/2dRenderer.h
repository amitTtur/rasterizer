#pragma once
#ifndef D2_RENDERER
#define D2_RENDERER

// misc includes
#include "sdlScreenHandler.h"
#include "Menu.h"

// object includes
#include "Triangle.h"

class D2_renderer
{
public:
	D2_renderer();
	~D2_renderer() = default;



private:
	std::vector<Object> _renderList;
	SdlHandler _sdlHandler;
};


#endif // !2D_RENDERER
