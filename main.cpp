#include <iostream>
#include <string>
#include <cstdlib>
#include "Rectangle.h"
#include "Point.h"

/**
 * @brief Считывает значение с клавиатуры
 * @param report - строка информации
 * @return считанное значение
 */
unsigned int getValue(std::string report = "");

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    // Установка разрешения экрана
    unsigned int screenResolution = getValue("enter screen resolution (max coordinate value): ");
    Point::setMaxValue(screenResolution);

    std::cout << "\n creating a rectangle using points3 \n" << std::endl;

    // Способ 1: через точки
    unsigned int x1 = getValue("enter x1: ");
    unsigned int y1 = getValue("enter y1: ");
    unsigned int x2 = getValue("enter x2: ");
    unsigned int y2 = getValue("enter y2: ");
    unsigned int x3 = getValue("enter x3: ");
    unsigned int y3 = getValue("enter y3: ");
    unsigned int x4 = getValue("enter x4: ");
    unsigned int y4 = getValue("enter y4: ");

    Point p1(x1, y1);
    Point p2(x2, y2);
    Point p3(x3, y3);
    Point p4(x4, y4);

    Rectangle rect1(p1, p2, p3, p4);
    rect1.draw();

    std::cout << "\n creating a rectangle using coordinates \n" << std::endl;

    // Способ 2: через пары чисел
    unsigned int a1 = getValue("enter x1: ");
    unsigned int b1 = getValue("enter y1: ");
    unsigned int a2 = getValue("enter x2: ");
    unsigned int b2 = getValue("enter y2: ");
    unsigned int a3 = getValue("enter x3: ");
    unsigned int b3 = getValue("enter y3: ");
    unsigned int a4 = getValue("enter x4: ");
    unsigned int b4 = getValue("enter y4: ");

    Rectangle rect2(a1, b1, a2, b2, a3, b3, a4, b4);
    rect2.draw();

    return 0;
}

unsigned int getValue(std::string report)
{
    std::cout << report;
    unsigned int value = 0;
    std::cin >> value;
    if (std::cin.fail())
    {
        std::cout << "error, invalid value entered.\n";
        exit(1);
    }
    return value;
}
