#include "2dRenderer.h"

D2_renderer::D2_renderer(const int screenWidth, const int screenHeight) :
	_sdlHandler(screenWidth,screenHeight,_screen) , _listChanged(false)
{
}

void D2_renderer::addShape(std::unique_ptr<Object> toAdd)
{
	_renderList.push_back(std::move(toAdd));
}
