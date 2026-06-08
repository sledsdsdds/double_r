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
     static int maxValue;  // максимальное значение (разрешение экрана)

public:
    /**
     * @brief Конструктор точки
     * @param x координата X
     * @param y координата Y
     */
    Point(int x = 0, int y = 0);

    /**
     * @brief Получение координаты X
     */
    unsigned int getX() const;

    /**
     * @brief Получение координаты Y
     */
    unsigned int getY() const;

    /**
     * @brief Установка максимального значения (разрешение экрана)
     * @param max максимальное значение
     */
    static void setMaxValue(int max);

    /**
     * @brief Получение максимального значения
     */
    static unsigned int getMaxValue();

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
    Point operator+(int value) const;

    /**
     * @brief Оператор вычитания точки с числом
     */
    Point operator-(int value) const;

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
