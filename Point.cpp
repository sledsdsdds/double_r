#include "Point.h"
#include <cmath>
#include <cstdlib>
#include <sstream>

unsigned int Point::maxValue = 1024;

Point::Point(unsigned int x, unsigned int y)
{
    if (x > maxValue || y > maxValue)
    {
        std::cout << "error. coordinates exceed screen resolution (max " << maxValue << ").\n";
        exit(1);
    }
    this->x = x;
    this->y = y;
}

unsigned int Point::getX() const
{
    return this->x;
}

unsigned int Point::getY() const
{
    return this->y;
}

void Point::setMaxValue(unsigned int max)
{
    maxValue = max;
}

unsigned int Point::getMaxValue()
{
    return maxValue;
}

std::string Point::toString() const
{
    std::stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
}

bool Point::operator==(const Point& p) const
{
    return (x == p.x && y == p.y);
}

bool Point::operator!=(const Point& p) const
{
    return !(*this == p);
}

Point Point::operator+(unsigned int value) const
{
    return Point(x + value, y + value);
}

Point Point::operator-(unsigned int value) const
{
    if (x < value || y < value)
    {
        std::cout << "error. subtraction result cannot be negative.\n";
        exit(1);
    }
    return Point(x - value, y - value);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
    std::cout << "enter point coordinates (x y): ";
    is >> p.x >> p.y;
    if (is.fail())
    {
        std::cout << "input error.\n";
        exit(1);
    }
    if (p.x > Point::maxValue || p.y > Point::maxValue)
    {
        std::cout << "error. coordinates exceed screen resolution (max " << Point::maxValue << ").\n";
        exit(1);
    }
    return is;
}

double Point::distanceTo(const Point& other) const
{
    double dx = (double)this->x - (double)other.x;
    double dy = (double)this->y - (double)other.y;
    return sqrt(dx * dx + dy * dy);
}
