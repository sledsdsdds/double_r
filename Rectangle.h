#pragma once
#include "Figure.h"
#include "point.h"

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
    void getSides(double& side1, double& side2) const;

public:
    /**
     * @brief Конструктор через точки
     */
    Rectangle(const Point& p1, const Point& p2,
        const Point& p3, const Point& p4);

    /**
     * @brief Конструктор через пары чисел
     */
    Rectangle(unsigned int x1, unsigned int y1,
        unsigned int x2, unsigned int y2,
        unsigned int x3, unsigned int y3,
        unsigned int x4, unsigned int y4);

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
