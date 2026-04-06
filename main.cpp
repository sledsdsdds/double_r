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

Point getPoint();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    std::cout << "Enter the coordinates of the four vertices of the rectangle: " << std::endl;

    Point p1 = getPoint();
    Point p2 = getPoint();
    Point p3 = getPoint();
    Point p4 = getPoint();

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

Point getPoint()
{
    double x = getValue("x: ");
    double y = getValue("y: ");
    return Point(x,y);
}
