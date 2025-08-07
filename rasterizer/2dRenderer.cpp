#include "2dRenderer.h"

D2_renderer::D2_renderer(usho screenWidth, usho screenHeight) :
	_sdlHandler(screenWidth,screenHeight,_screen) , _listChanged(false)
{
	_screen.resize(_sdlHandler.getHeight());
	for (std::vector<Color> vec : _screen)
	{
		vec.resize(_sdlHandler.getWidth());
	}
}

void D2_renderer::addShape(std::unique_ptr<Object> toAdd)
{
	_renderList.push_back(std::move(toAdd));
	_sdlHandler.updateScreen();
}

void D2_renderer::proccessShapes()
{
	// NOTE: add an edge case for circle, only 1 point would cause a array oob err

	// drawing proccess is a agreed format, so that
	// the drawing is goes like this: p1 -> p2 -> ... -> pn -> p1

	Point a;
	Point b;
	long double m = 0.0;
	// go over every shape
	for (size_t i = 0; i < _renderList.size(); i++)
	{
		Object* shape = _renderList[i].get(); // shape at the iTH position 
		// shape points, const so the fucntion wont accidentally
		// change the points
		const std::vector<Point>& points = shape->getObjectPoints(); 
		// shape color
		const Color& color = shape->getColor();

		// using the Bresenham's line algorithm to draw the outline of the shape
		for (size_t j = 0; j <= points.size()-1; j++)
		{
			a = points[j]; // start point
			b = points[j == points.size() - 1 ? 0 : j + 1]; // end point

			// multiple x can result in y and vice versa
			// this code segment aims to get the most accurate 
			// result by getting the longer segment of pixels in each axis
			int disY = b.getY() - a.getY();
			int disX = b.getX() - a.getX();

			// means following x would be more accurate
			if (abs(disY) < abs(disX))
			{
				if (!disX) continue;

				// claculate m
				// (Yb - Ya) / (Xb - Xa)
				m = static_cast<long double>((b.getY() - a.getY()) / (b.getX() - a.getX()));
				for (int k = 0; k <= abs(disX); k++)
				{
					int endX = a.getX() + (disX < 0 ? -k : k);
					int endY = m * (endX - a.getX()) + a.getY();
					if (endX >= 0 && endY >= 0)
					{
						_screen[endY][endX] = color;
					}
				}
			}
			else // go by the y axis
			{
				if (!disY) continue;
				// claculate m
				// (Xb - Xa) / (Yb - Ya)
				m = static_cast<long double>((b.getX() - a.getX()) / (b.getY() - a.getY()));

				for (int k = 0; k <= abs(disY); k++)
				{
					int endY = a.getY() + (disY < 0 ? -k : k);
					int endX = m * (endY - a.getY()) + a.getX();
					if (endX >= 0 && endY >= 0)
					{
						_screen[endY][endX] = color;
					}
				}
			}	
		}
	}
}
