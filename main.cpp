#include <iostream>
#include "rectangle.h"
#include "point.h"
#include <locale.h>


/**
 * @brief Считывает значение, введенное с клавиатуры
 * @param report - строка информации
 * @return считанное значение
 */
double getValue(std::string report = "");

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    std::cout << "Enter the coordinates of the four vertices of the rectangle: " << std::endl;

    double x1 = getValue("x1: ");
    double y1 = getValue("y1: ");
    double x2 = getValue("x2: ");
    double y2 = getValue("y2: ");
    double x3 = getValue("x3: ");
    double y3 = getValue("y3: ");
    double x4 = getValue("x4: ");
    double y4 = getValue("y4: ");

    Point p1(x1, y1);
    Point p2(x2, y2);
    Point p3(x3, y3);
    Point p4(x4, y4);

    Rectangle myRectangle(p1, p2, p3, p4);

    std::cout << "\nResults:" << std::endl;
    std::cout << "Rectangle area: " << myRectangle.getArea() << std::endl;
    std::cout << "The radius of the circumscribed circle: " << myRectangle.getCircumscribedCircleRadius() << std::endl;

    return 0;
}

double getValue(std::string report)
{
    std::cout << report;
    double value = 0;
    std::cin >> value;
    if (std::cin.fail())
    {
        std::cout << "Error, incorrect value entered!\n";
        exit(1);
    }
    return value;
}
