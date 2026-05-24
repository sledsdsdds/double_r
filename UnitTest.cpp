#include "CppUnitTest.h"
#include "../222222222.7/Rectangle.h"
#include "../222222222.7/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Тестовые функции
Rectangle createTestRectangle1()
{
    return Rectangle(0, 0, 4, 0, 4, 3, 0, 3);
}

Rectangle createTestRectangle2()
{
    return Rectangle(0, 0, 5, 0, 5, 5, 0, 5);
}

namespace RectangleTests
{
    TEST_CLASS(RectangleTest)
    {
    public:
        // Тест 1: Проверка площади прямоугольника 4x3
        TEST_METHOD(Rectangle_Area_4x3)
        {
            Rectangle rect = createTestRectangle1();
            double expectedArea = 12.0;
            double actualArea = rect.getArea();
            Assert::AreEqual(expectedArea, actualArea, 0.01);
        }

        // Тест 2: Проверка радиуса описанной окружности (4x3)
        TEST_METHOD(Rectangle_Radius_4x3)
        {
            Rectangle rect = createTestRectangle1();
            double expectedRadius = 2.5;
            double actualRadius = rect.getCircumscribedCircleRadius();
            Assert::AreEqual(expectedRadius, actualRadius, 0.01);
        }

        // Тест 3: Проверка площади квадрата 5x5
        TEST_METHOD(Square_Area_5x5)
        {
            Rectangle square = createTestRectangle2();
            double expectedArea = 25.0;
            double actualArea = square.getArea();
            Assert::AreEqual(expectedArea, actualArea, 0.01);
        }

        // Тест 4: Проверка радиуса описанной окружности (квадрат 5x5)
        TEST_METHOD(Square_Radius_5x5)
        {
            Rectangle square = createTestRectangle2();
            double expectedRadius = 3.535;
            double actualRadius = square.getCircumscribedCircleRadius();
            Assert::AreEqual(expectedRadius, actualRadius, 0.01);
        }
    };
}
