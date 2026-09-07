#include "Rectangle.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <sstream>

Rectangle::Rectangle(const Point& p1, const Point& p2,
    const Point& p3, const Point& p4)
    : p1(p1), p2(p2), p3(p3), p4(p4)
{
    if (!isRectangle())
    {
        std::cout << "error. four points do not form a rectangle.\n";
        exit(1);
    }
}

Rectangle::Rectangle(const int x1, const int y1,
        const int x2, const int y2,
        const int x3, const int y3,
        const int x4, const int y4)
    : p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4)
{
    if (!isRectangle())
    {
        std::cout << "error. four points do not form a rectangle.\n";
        exit(1);
    }
}

bool Rectangle::isRectangle() const
{
    double d12 = p1.distanceTo(p2);
    double d23 = p2.distanceTo(p3);
    double d34 = p3.distanceTo(p4);
    double d41 = p4.distanceTo(p1);
    double d13 = p1.distanceTo(p3);
    double d24 = p2.distanceTo(p4);

    double eps = std::numeric_limits<double>::epsilon();

    // Противоположные стороны равны
    if (std::abs(d12 - d34) > eps) return false;
    if (std::abs(d23 - d41) > eps) return false;

    // Диагонали равны
    if (std::abs(d13 - d24) > eps) return false;

    // Теорема Пифагора
    if (std::abs(d12 * d12 + d23 * d23 - d13 * d13) > eps) return false;

    // Проверка на вырожденность
    if (d12 < eps || d23 < eps) return false;

    return true;
}

std::pair<double, double> Rectangle::getSides() const
{
    double side1 = p1.distanceTo(p2);
    double side2 = p2.distanceTo(p3);
    if (side1 > side2) std::swap(side1, side2);
    return { side1, side2 };
}

Point Rectangle::getP1() const { return p1; }
Point Rectangle::getP2() const { return p2; }
Point Rectangle::getP3() const { return p3; }
Point Rectangle::getP4() const { return p4; }

std::string Rectangle::toString() const
{
    std::stringstream ss;
    ss << "rectangle: " << p1.toString() << ", "
        << p2.toString() << ", "
        << p3.toString() << ", "
        << p4.toString();
    return ss.str();
}

void Rectangle::draw() const
{
    std::cout << toString() << std::endl;
    std::cout << "area: " << getArea() << std::endl;
    std::cout << "circumscribed circle radius: " << getCircumscribedCircleRadius() << std::endl;
}

void Rectangle::read()
{
    std::cout << "enter the vertices of the rectangle:" << std::endl;
    std::cin >> p1 >> p2 >> p3 >> p4;

    if (!isRectangle())
    {
        std::cout << "error. the entered points do not form a rectangle.\n";
        exit(1);
    }
}

Rectangle Rectangle::readFromStream()
{
    Point p1, p2, p3, p4;
    std::cin >> p1 >> p2 >> p3 >> p4;
    return Rectangle(p1, p2, p3, p4);
}

double Rectangle::getArea() const
{
    auto sides = getSides();
    return sides.first * sides.second;
}

double Rectangle::getCircumscribedCircleRadius() const
{
    auto sides = getSides();
    return std::sqrt(sides.first * sides.first + sides.second * sides.second) / 2.0;
}
