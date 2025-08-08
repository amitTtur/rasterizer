#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "point.h"

#define PI    3.14159265358979323846264338327950288
#define to_radians(x) ((x) * (PI / 180.0))
#define to_degrees(x) ((x) * (180.0 / PI))


class Object
{
public:
	Object(Color color);
	virtual ~Object() = default;

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

	// calculate using cis
	std::vector<Point> calculatePoints(Point start,uchar sides) const;

protected:

private:
	static unsigned int count;

	unsigned int _id;
	Color _color;

	Point getCordsFromCis(long double Radius, long double theta) const;
};

#endif