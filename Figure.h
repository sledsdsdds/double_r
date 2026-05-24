#pragma once
#include <string>

/**
 * @brief Абстрактный базовый класс Фигура на плоскости
 */
class Figure
{
public:
    virtual ~Figure() = default;

    /**
     * @brief Сериализация фигуры в строку
     * @return строковое представление фигуры
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Рисование фигуры (вывод информации)
     */
    virtual void draw() const = 0;

    /**
     * @brief Чтение фигуры из стандартного потока ввода
     */
    virtual void read() = 0;
};
