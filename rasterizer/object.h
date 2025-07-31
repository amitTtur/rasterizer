#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "point.h"

class Object
{
public:
	virtual std::vector<Point> getObjectPoints() const = 0;

	Color getColor() const noexcept { return _color; }
	Color setColor(uchar r, uchar g, uchar b, uchar a) noexcept
	{
		_color.a = a;
		_color.b = b;
		_color.g = g;
		_color.r = r;
	}
	Color setColor(Color color) noexcept { _color = color; }

protected:

private:
	Color _color;
};

#endif