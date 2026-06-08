#include "Point.h"
#include <cmath>
#include <cstdlib>
#include <sstream>

int Point::maxValue = 1024;

Point::Point(int x, int y)
{
    if (x < 0 || y < 0)
    {
        std::cout << "error. coordinates cannot be negative.\n";
        exit(1);
    }
    if (x > maxValue || y > maxValue)
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
    if (max <= 0)
    {
        std::cout << "error. max value must be positive.\n";
        exit(1);
    }
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
    if (value < 0)
    {
        std::cout << "error. cannot add negative number.\n";
        exit(1);
    }
    int newX = x + value;
    int newY = y + value;
    if (newX > maxValue || newY > maxValue)
    {
        std::cout << "error. result exceeds screen resolution.\n";
        exit(1);
    }
    return Point(newX, newY);
}

Point Point::operator-(int value) const
{
    if (value < 0)
    {
        std::cout << "error. cannot subtract negative number.\n";
        exit(1);
    }
    int newX = x - value;
    int newY = y - value;
    if (newX < 0 || newY < 0)
    {
        std::cout << "error. subtraction result cannot be negative.\n";
        exit(1);
    }
    return Point(newX, newY);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
    int tx, ty;
    std::cout << "enter point coordinates (x y): ";
    is >> tx >> ty;
    if (is.fail())
    {
        std::cout << "input error.\n";
        exit(1);
    }
    if (tx < 0 || ty < 0)
    {
        std::cout << "error. coordinates cannot be negative.\n";
        exit(1);
    }
    if (tx > Point::maxValue || ty > Point::maxValue)
    {
        std::cout << "error. coordinates exceed screen resolution (max " << Point::maxValue << ").\n";
        exit(1);
    }
    p.x = tx;
    p.y = ty;
    return is;
}

double Point::distanceTo(const Point& other) const
{
    double dx = (double)this->x - (double)other.x;
    double dy = (double)this->y - (double)other.y;
    return sqrt(dx * dx + dy * dy);
}
