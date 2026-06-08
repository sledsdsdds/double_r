#pragma once
#include "Figure.h"
#include "point.h"
#include <utility>

/**
 * @brief Класс Прямоугольник
 */
class Rectangle : public Figure
{
private:
    Point p1, p2, p3, p4;

    /**
     * @brief Проверка, является ли фигура прямоугольником
     * @return true, если четыре точки образуют прямоугольник
     */
    bool isRectangle() const;

    /**
     * @brief Получение сторон прямоугольника
     * @param side1 первая сторона
     * @param side2 вторая сторона
     */
    std::pair<double, double> getSides() const;

public:
    /**
     * @brief Конструктор через точки
     */
    Rectangle(const Point& p1, const Point& p2,
        const Point& p3, const Point& p4);

    /**
     * @brief Конструктор через пары чисел
     */
    Rectangle(int x1, int y1,
              int x2, int y2,
              int x3, int y3,
              int x4, int y4);

    /**
     * @brief Получение вершин прямоугольника
     */
    Point getP1() const;
    Point getP2() const;
    Point getP3() const;
    Point getP4() const;

    /**
     * @brief Сериализация в строку
     */
    std::string toString() const override;

    /**
     * @brief Рисование фигуры
     */
    void draw() const override;

    /**
     * @brief Чтение фигуры из потока
     */
    void read() override;

    /**
     * @brief Статический метод чтения прямоугольника
     */
    static Rectangle readFromStream();

    /**
     * @brief Вычисление площади
     */
    double getArea() const;

    /**
     * @brief Вычисление радиуса описанной окружности
     */
    double getCircumscribedCircleRadius() const;
};
