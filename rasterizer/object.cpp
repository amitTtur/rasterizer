#include "object.h"

unsigned int Object::count = 0;

Object::Object(Color color) : _color(color) {
	_id = count;
	count++;
}


std::vector<Point> Object::calculatePoints(Point start, uchar sides) const
{
	std::vector<Point> ret;
	long double radius = sqrt(pow(start.getX(), 2) + pow(start.getY(), 2));
	long double theta = to_degrees(atan2(start.getY(), start.getX())); 
	long double jumpSide = 360.0 / sides;

	for (int i = 0; i < sides; ++i)
	{
		ret.push_back(getCordsFromCis(radius, theta + i * jumpSide));
	}

	return ret;
}

Point Object::getCordsFromCis(long double Radius, long double theta) const
{
	Point ret;
	ret.setX(Radius * cos(to_radians(theta)));
	ret.setY(Radius * sin(to_radians(theta)));
	return ret;
}
