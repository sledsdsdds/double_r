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

bool Point::operator==(const Point& p) const
{
    const double eps = 1e-9;
    return (std::abs(this->x - p.x) < eps && std::abs(this->y - p.y) < eps);
}

bool Point::operator!=(const Point& p) const
{
    return !(*this == p);
}

double Point::distanceTo(const Point& other) const
{
    double dx = this->x - other.x;
    double dy = this->y - other.y;
    return sqrt(dx * dx + dy * dy);
}
