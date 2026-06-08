#include "Point.h"
#include <cmath>
#include <cstdlib>
#include <sstream>

int Point::maxValue = 1024;

Point::Point(int x, int y)
{
    if (x > maxValue || y > maxValue || x < -maxValue || y < -maxValue)
    {
        std::cout << "error. coordinates exceed screen resolution (max " << maxValue << ").\n";
        exit(1);
    }
    this->x = x;
    this->y = y;
}

int Point::getX() const
{
    return this->x;
}

int Point::getY() const
{
    return this->y;
}

void Point::setMaxValue(int max)
{
    maxValue = max;
}

int Point::getMaxValue()
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

Point Point::operator+(int value) const
{
    return Point(x + value, y + value);
}

Point Point::operator-(int value) const
{
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
    if (p.x > Point::maxValue || p.y > Point::maxValue ||
        p.x < -Point::maxValue || p.y < -Point::maxValue)
    {
        std::cout << "error. coordinates exceed screen resolution (max " << Point::maxValue << ").\n";
        exit(1);
    }
    return is;
}

double Point::distanceTo(const Point& other) const
{
    double dx = static_cast<double>(this->x) - static_cast<double>(other.x);
    double dy = static_cast<double>(this->y) - static_cast<double>(other.y);
    return sqrt(dx * dx + dy * dy);
}
