#include "Triangle.h"

std::vector<Point> Triangle::getObjectPoints() const
{
    std::vector<Point> ret;
    ret.push_back(_p1);
    ret.push_back(_p2);
    ret.push_back(_p3);
    return ret;
}
