#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "point.h"


class Object
{
public:
	Object(Color color);

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

	int getId() const { return _id; }

protected:

private:
	static unsigned int count;

	unsigned int _id;
	Color _color;
};

#endif