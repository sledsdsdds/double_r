#pragma once
#include <iostream>
#include <string>

/**
 * @brief Класс Точка на плоскости
 */
class Point
{
private:
    int x;  // абсцисса
    int y;  // ордината
    static const int maxValue;  // максимальное значение (разрешение экрана) - const

public:
    /**
     * @brief Конструктор точки
     * @param x координата X
     * @param y координата Y
     */
    Point(const int x = 0,const int y = 0);

    /**
     * @brief Получение координаты X
     */
    int getX() const;

    /**
     * @brief Получение координаты Y
     */
    int getY() const;

    /**
     * @brief Получение максимального значения
     */
    static int getMaxValue() const;

    /**
     * @brief Преобразование в строку
     */
    std::string toString() const;

    /**
     * @brief Оператор сравнения ==
     */
    bool operator==(const Point& p) const;

    /**
     * @brief Оператор сравнения !=
     */
    bool operator!=(const Point& p) const;

    /**
     * @brief Оператор сложения точки с числом
     */
    Point operator+(const int value);

    /**
     * @brief Оператор вычитания точки с числом
     */
    Point operator-(const int value);

    /**
     * @brief Оператор вывода в поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /**
     * @brief Оператор ввода из потока
     */
    friend std::istream& operator>>(std::istream& is, Point& p);

    /**
     * @brief Расстояние между двумя точками
     */
    double distanceTo(const Point& other) const;
};
