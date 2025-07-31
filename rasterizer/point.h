#pragma once

#ifndef POINT_H

#include "./defines.hpp"

class Point {
public:
	Point() : _x(0), _y(0) {};
	Point(unsigned short x, unsigned short y) : _x(x), _y(y) {};
	~Point() = default;

	usho getX() { return _x; }
	usho getY() { return _y; }
	usho setX(usho x) { _x = x; }
	usho setY(usho y) { _y= y; }

private:
	usho _x; // in pixels
	usho _y; // in pixels
};

#endif // !1