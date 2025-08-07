#include "Triangle.h"

Triangle::Triangle(Color color, Point p1) : Object(color), _p1(p1) 
{
    auto tmp = calculatePoints(p1,3);
    _p1 = tmp[0];
    _p2 = tmp[1];
    _p3 = tmp[2];
}

std::vector<Point> Triangle::getObjectPoints() const
{
    std::vector<Point> ret;
    
    ret.push_back(_p1);
    ret.push_back(_p2);
    ret.push_back(_p3);
    return ret;
}
