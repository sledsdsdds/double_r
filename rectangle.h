#pragma once
#include "point.h"

/**
 * @brief Класс Прямоугольник
 */
class Rectangle
{
private:
    /**
     * @brief Четыре вершины прямоугольника
     */
    Point p1, p2, p3, p4;

    /**
     * @brief Проверка, образуют ли четыре точки прямоугольник
     */
    bool isRectangle() const;

    /**
     * @brief Получение длин сторон прямоугольника
     * @param side1 - первая сторона
     * @param side2 - вторая сторона
     */
    void getSides(double& side1, double& side2) const;

public:
    /**
     * @brief Конструктор
     * @param p1 - первая вершина
     * @param p2 - вторая вершина
     * @param p3 - третья вершина
     * @param p4 - четвертая вершина
     */
    Rectangle(Point p1, Point p2, Point p3, Point p4);

    /**
     * @brief Расчет площади прямоугольника
     */
    double getArea() const;

    /**
     * @brief Расчет радиуса описанной окружности
     */
    double getCircumscribedCircleRadius() const;
};
