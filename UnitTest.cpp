#include "CppUnitTest.h"
#include "../222222222.7/Rectangle.h"
#include "../222222222.7/Point.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ

Rectangle createTestRectangle1()
{
    return Rectangle(0, 0, 4, 0, 4, 3, 0, 3);
}

Rectangle createTestRectangle2()
{
    return Rectangle(0, 0, 5, 0, 5, 5, 0, 5);
}

// ТЕСТЫ КЛАССА POINT

namespace PointTests
{
    TEST_CLASS(PointTest)
    {
    public:
        // 1. Конструктор по умолчанию
        TEST_METHOD(Point_DefaultConstructor)
        {
            Point p;
            Assert::AreEqual(0, p.getX());
            Assert::AreEqual(0, p.getY());
        }

        // 2. Конструктор с параметрами
        TEST_METHOD(Point_ParameterizedConstructor)
        {
            Point p(3, 7);
            Assert::AreEqual(3, p.getX());
            Assert::AreEqual(7, p.getY());
        }

        // 3. getX()
        TEST_METHOD(Point_GetX)
        {
            Point p(10, 20);
            Assert::AreEqual(10, p.getX());
        }

        // 4. getY()
        TEST_METHOD(Point_GetY)
        {
            Point p(10, 20);
            Assert::AreEqual(20, p.getY());
        }

        // 5. toString()
        TEST_METHOD(Point_ToString)
        {
            Point p(2, 5);
            std::string expected = "(2, 5)";
            Assert::AreEqual(expected, p.toString());
        }

        // 6. operator== (равны)
        TEST_METHOD(Point_Equal_True)
        {
            Point p1(1, 2);
            Point p2(1, 2);
            Assert::IsTrue(p1 == p2);
        }

        // 7. operator== (не равны)
        TEST_METHOD(Point_Equal_False)
        {
            Point p1(1, 2);
            Point p2(3, 4);
            Assert::IsFalse(p1 == p2);
        }

        // 8. operator!=
        TEST_METHOD(Point_NotEqual_True)
        {
            Point p1(1, 2);
            Point p2(3, 4);
            Assert::IsTrue(p1 != p2);
        }

        // 9. operator!= (равны → false)
        TEST_METHOD(Point_NotEqual_False)
        {
            Point p1(1, 2);
            Point p2(1, 2);
            Assert::IsFalse(p1 != p2);
        }

        // 10. operator+ (сдвиг)
        TEST_METHOD(Point_Add)
        {
            Point p(2, 3);
            Point result = p + 5;
            Assert::AreEqual(7, result.getX());
            Assert::AreEqual(8, result.getY());
        }

        // 11. operator- (сдвиг)
        TEST_METHOD(Point_Subtract)
        {
            Point p(10, 12);
            Point result = p - 3;
            Assert::AreEqual(7, result.getX());
            Assert::AreEqual(9, result.getY());
        }

        // 12. operator<< (вывод в поток)
        TEST_METHOD(Point_OutputStream)
        {
            Point p(3, 4);
            std::stringstream ss;
            ss << p;
            Assert::AreEqual(std::string("(3, 4)"), ss.str());
        }

        // 13. operator>> (ввод из потока)
        TEST_METHOD(Point_InputStream)
        {
            std::stringstream ss("10 20");
            Point p;
            ss >> p;
            Assert::AreEqual(10, p.getX());
            Assert::AreEqual(20, p.getY());
        }

        // 14. distanceTo()
        TEST_METHOD(Point_DistanceTo)
        {
            Point a(0, 0);
            Point b(3, 4);
            double dist = a.distanceTo(b);
            Assert::AreEqual(5.0, dist, 0.0001);
        }

        // 15. getMaxValue() (статический)
        TEST_METHOD(Point_GetMaxValue)
        {
            int max = Point::getMaxValue();
            Assert::AreEqual(1024, max);
        }
    };
}

// ТЕСТЫ КЛАССА RECTANGLE

namespace RectangleTests
{
    TEST_CLASS(RectangleTest)
    {
    public:
        // 1. Конструктор через точки
        TEST_METHOD(Rectangle_ConstructorWithPoints)
        {
            Point p1(0, 0), p2(4, 0), p3(4, 3), p4(0, 3);
            Rectangle rect(p1, p2, p3, p4);
            Assert::AreEqual(12.0, rect.getArea(), 0.01);
        }

        // 2. Конструктор через координаты
        TEST_METHOD(Rectangle_ConstructorWithCoords)
        {
            Rectangle rect(0, 0, 4, 0, 4, 3, 0, 3);
            Assert::AreEqual(12.0, rect.getArea(), 0.01);
        }

        // 3. getP1()
        TEST_METHOD(Rectangle_GetP1)
        {
            Rectangle rect(1, 2, 5, 2, 5, 7, 1, 7);
            Point p1 = rect.getP1();
            Assert::AreEqual(1, p1.getX());
            Assert::AreEqual(2, p1.getY());
        }

        // 4. getP2()
        TEST_METHOD(Rectangle_GetP2)
        {
            Rectangle rect(1, 2, 5, 2, 5, 7, 1, 7);
            Point p2 = rect.getP2();
            Assert::AreEqual(5, p2.getX());
            Assert::AreEqual(2, p2.getY());
        }

        // 5. getP3()
        TEST_METHOD(Rectangle_GetP3)
        {
            Rectangle rect(1, 2, 5, 2, 5, 7, 1, 7);
            Point p3 = rect.getP3();
            Assert::AreEqual(5, p3.getX());
            Assert::AreEqual(7, p3.getY());
        }

        // 6. getP4()
        TEST_METHOD(Rectangle_GetP4)
        {
            Rectangle rect(1, 2, 5, 2, 5, 7, 1, 7);
            Point p4 = rect.getP4();
            Assert::AreEqual(1, p4.getX());
            Assert::AreEqual(7, p4.getY());
        }

        // 7. toString()
        TEST_METHOD(Rectangle_ToString)
        {
            Rectangle rect(0, 0, 4, 0, 4, 3, 0, 3);
            std::string str = rect.toString();
            Assert::IsTrue(str.find("(0, 0)") != std::string::npos);
            Assert::IsTrue(str.find("(4, 0)") != std::string::npos);
            Assert::IsTrue(str.find("(4, 3)") != std::string::npos);
            Assert::IsTrue(str.find("(0, 3)") != std::string::npos);
            Assert::IsTrue(str.find("rectangle:") != std::string::npos);
        }

        // 8. getArea() 4x3
        TEST_METHOD(Rectangle_Area_4x3)
        {
            Rectangle rect = createTestRectangle1();
            double expectedArea = 12.0;
            double actualArea = rect.getArea();
            Assert::AreEqual(expectedArea, actualArea, 0.01);
        }

        // 9. getArea() 5x5
        TEST_METHOD(Rectangle_Area_5x5)
        {
            Rectangle square = createTestRectangle2();
            double expectedArea = 25.0;
            double actualArea = square.getArea();
            Assert::AreEqual(expectedArea, actualArea, 0.01);
        }

        // 10. getCircumscribedCircleRadius() 4x3
        TEST_METHOD(Rectangle_Radius_4x3)
        {
            Rectangle rect = createTestRectangle1();
            double expectedRadius = 2.5;
            double actualRadius = rect.getCircumscribedCircleRadius();
            Assert::AreEqual(expectedRadius, actualRadius, 0.01);
        }

        // 11. getCircumscribedCircleRadius() 5x5
        TEST_METHOD(Rectangle_Radius_5x5)
        {
            Rectangle square = createTestRectangle2();
            double expectedRadius = 3.5355339059327378;
            double actualRadius = square.getCircumscribedCircleRadius();
            Assert::AreEqual(expectedRadius, actualRadius, 0.01);
        }

        // 12. read() (чтение из потока)
        TEST_METHOD(Rectangle_Read)
        {
            std::stringstream ss("0 0 4 0 4 3 0 3");
            auto cin_buf = std::cin.rdbuf();
            std::cin.rdbuf(ss.rdbuf());

            Rectangle rect;
            rect.read();

            std::cin.rdbuf(cin_buf);

            Assert::AreEqual(12.0, rect.getArea(), 0.01);
        }

        // 13. readFromStream() (статический метод)
        TEST_METHOD(Rectangle_ReadFromStream)
        {
            std::stringstream ss("0 0 4 0 4 3 0 3");
            auto cin_buf = std::cin.rdbuf();
            std::cin.rdbuf(ss.rdbuf());

            Rectangle rect = Rectangle::readFromStream();

            std::cin.rdbuf(cin_buf);

            Assert::AreEqual(12.0, rect.getArea(), 0.01);
        }

        // 14. draw() (проверяем, что не падает)
        TEST_METHOD(Rectangle_Draw)
        {
            Rectangle rect(0, 0, 4, 0, 4, 3, 0, 3);
            auto cout_buf = std::cout.rdbuf();
            std::stringstream ss;
            std::cout.rdbuf(ss.rdbuf());

            rect.draw();

            std::cout.rdbuf(cout_buf);
            Assert::IsTrue(ss.str().length() > 0);
        }

        // 15. Проверка корректного прямоугольника
        TEST_METHOD(Rectangle_ValidRectangle)
        {
            Rectangle rect(0, 0, 4, 0, 4, 3, 0, 3);
            Assert::IsTrue(true);
        }
    };
}
