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
class Triangle : public Object {
public:
	Triangle(Color color,Point p1);
	Triangle() = delete;
	virtual ~Triangle() = default;

	virtual std::vector<Point> getObjectPoints() const override;


private:
	Point _p1;
	Point _p2; 
	Point _p3; 
};

#endif // !1