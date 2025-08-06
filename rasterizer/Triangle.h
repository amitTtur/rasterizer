#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object.h"

/*

p1
|\
| \
|  \
|   \
------
p2     p3

*/
class Triangle : Object {
public:
	Triangle(Color color,Point p1, Point p2, Point p3) : Object(color), _p1(p1), _p2(p2), _p3(p3) {};
	Triangle() = delete;
	~Triangle() = default;

	virtual std::vector<Point> getObjectPoints() const override;


private:
	Point _p1;
	Point _p2; 
	Point _p3; 
};

#endif // !1