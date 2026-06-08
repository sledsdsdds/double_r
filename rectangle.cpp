#include <iostream>
#include <cmath>
#include <algorithm>
#include "rectangle.h"

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;

    // Проверка на совпадение точек
    if (p1 == p2 || p1 == p3 || p1 == p4 ||
        p2 == p3 || p2 == p4 || p3 == p4)
    {
        std::cout << "Error: The points match!" << std::endl;
        exit(1);
    }

    if (!isRectangle())
    {
        std::cout << "Error: Four points do not form a rectangle!" << std::endl;
        exit(1);
    }
}

bool Rectangle::isRectangle() const
{
    // Вычисляем все расстояния между точками
    double d12 = p1.distanceTo(p2);
    double d13 = p1.distanceTo(p3);
    double d14 = p1.distanceTo(p4);
    double d23 = p2.distanceTo(p3);
    double d24 = p2.distanceTo(p4);
    double d34 = p3.distanceTo(p4);

    double eps = 1e-9;

    // Для прямоугольника должно быть 4 стороны и 2 диагонали
    // Сортируем расстояния
    double dists[6] = { d12, d13, d14, d23, d24, d34 };
    std::sort(dists, dists + 6);

    // В прямоугольнике должно быть 4 равных стороны (попарно) и 2 равные диагонали
    // Проверяем, что первые 4 расстояния - это стороны (попарно равны)
    if (std::abs(dists[0] - dists[1]) > eps) return false;
    if (std::abs(dists[2] - dists[3]) > eps) return false;

    // Проверяем, что две диагонали равны
    if (std::abs(dists[4] - dists[5]) > eps) return false;

    // Проверяем теорему Пифагора для сторон и диагонали
    double side1 = dists[0];
    double side2 = dists[2];
    double diagonal = dists[4];

    if (std::abs(side1 * side1 + side2 * side2 - diagonal * diagonal) > eps)
        return false;

    return true;
}

void Rectangle::getSides(double& side1, double& side2) const
{
    // Находим стороны прямоугольника
    double d12 = p1.distanceTo(p2);
    double d13 = p1.distanceTo(p3);
    double d14 = p1.distanceTo(p4);

    // Стороны - это расстояния от p1 до соседних вершин
    // Находим два наименьших расстояния из трех (это и будут стороны)
    double sides[3] = { d12, d13, d14 };
    std::sort(sides, sides + 3);

    side1 = sides[0];
    side2 = sides[1];
}

double Rectangle::getArea() const
{
    double side1, side2;
    getSides(side1, side2);
    return side1 * side2;
}

double Rectangle::getCircumscribedCircleRadius() const
{
    // Радиус описанной окружности = половина диагонали. Находим диагональ как максимальное расстояние между любыми двумя точками
    double d12 = p1.distanceTo(p2);
    double d13 = p1.distanceTo(p3);
    double d14 = p1.distanceTo(p4);
    double d23 = p2.distanceTo(p3);
    double d24 = p2.distanceTo(p4);
    double d34 = p3.distanceTo(p4);

    double diagonal = std::max({ d12, d13, d14, d23, d24, d34 });

    return diagonal / 2.0;
}
