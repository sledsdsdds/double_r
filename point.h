#pragma once

/**
 * @brief Класс Точка
 */
class Point
{
private:
    /**
     * @brief Координата X
     */
    double x;

    /**
     * @brief Координата Y
     */
    double y;

public:
    /**
     * @brief Конструктор точки
     */
    Point(double x = 0, double y = 0);

    /**
     * @brief Получение координаты X
     */
    double getX() const;

    /**
     * @brief Получение координаты Y
     */
    double getY() const;

    /**
     * @brief Проверка на равенство оператора
     */
    bool operator==(Point p) const;

    /**
     * @brief Проверка на неравенство оператора
     */
    bool operator!=(Point p) const;

    /**
     * @brief Расстояние между двумя точками
     */
    double distanceTo(const Point& other) const;
};
