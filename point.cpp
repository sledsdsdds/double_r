#include "point.h"
#include <cmath>

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

bool Point::operator==(Point p) const
{
    if (this->x == p.x && this->y == p.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Point::operator!=(Point p) const
{
    if (this->x != p.x || this->y != p.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Point::distanceTo(const Point& other) const
{
    double dx = this->x - other.x;
    double dy = this->y - other.y;
    return sqrt(dx * dx + dy * dy);
}
