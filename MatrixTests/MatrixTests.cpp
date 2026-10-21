#include <iostream>
#include <memory>
#include <vector>

#include "Matrix.h"
#include "ConstantGenerator.h"
#include "Task1.h"
#include "Task2.h"

using namespace miit::algebra;

namespace
{
    int passed = 0;
    int failed = 0;
}

#define CHECK(cond)                                                         \
    do {                                                                    \
        if (cond) { ++passed; }                                             \
        else {                                                              \
            ++failed;                                                       \
            std::cerr << "FAILED: " #cond " (line " << __LINE__ << ")\n";   \
        }                                                                   \
    } while (0)

namespace
{
    Matrix<int> makeMatrix(std::size_t r, std::size_t c, int value)
    {
        ConstantGenerator g(value);
        return Matrix<int>(r, c, g);
    }

    void testConstructors()
    {
        Matrix<int> m1;
        CHECK(m1.getRows() == 0);
        CHECK(m1.getCols() == 0);
        CHECK(m1.empty());

        Matrix<int> m2(2, 3);
        CHECK(m2.getRows() == 2);
        CHECK(m2.getCols() == 3);
        CHECK(!m2.empty());
        CHECK(m2[0][0] == 0);

        Matrix<int> m3 = makeMatrix(2, 2, 7);
        CHECK(m3[1][1] == 7);

        Matrix<int> m4 = m3;
        CHECK(m4[0][0] == 7);

        Matrix<int> m5 = std::move(m4);
        CHECK(m5[0][0] == 7);
    }

    void testIndexOperator()
    {
        Matrix<int> m = makeMatrix(2, 2, 5);
        m[0][1] = 42;
        CHECK(m[0][1] == 42);

        const Matrix<int>& cm = m;
        CHECK(cm[0][1] == 42);
        CHECK(cm.getRow(0)[1] == 42);
    }

    void testShift()
    {
        ConstantGenerator g(0);
        Matrix<int> m(1, 4, g);
        m[0][0] = 1;
        m[0][1] = 2;
        m[0][2] = 3;
        m[0][3] = 4;

        m << 1;
        CHECK(m[0][0] == 2);
        CHECK(m[0][1] == 3);
        CHECK(m[0][2] == 4);
        CHECK(m[0][3] == 1);

        m >> 1;
        CHECK(m[0][0] == 1);
        CHECK(m[0][1] == 2);
        CHECK(m[0][2] == 3);
        CHECK(m[0][3] == 4);
    }

    void testTask1()
    {
        ConstantGenerator g(0);
        Matrix<int> m(2, 3, g);
        m[0][0] = 1; m[0][1] = 5; m[0][2] = 3;
        m[1][0] = 4; m[1][1] = 2; m[1][2] = 6;

        Task1 t(m, std::make_shared<ConstantGenerator>(0));
        t.solve();

        const Matrix<int>& r = t.getMatrix();
        CHECK(r[1][0] == 0);
        CHECK(r[0][1] == 0);
        CHECK(r[1][2] == 0);
        CHECK(r[0][0] == 1);
    }

    void testTask2()
    {
        ConstantGenerator g(0);
        Matrix<int> m(2, 2, g);
        m[0][0] = -9; m[0][1] = 1;
        m[1][0] = 2; m[1][1] = 3;

        Task2 t(m, std::make_shared<ConstantGenerator>(0));
        t.solve();

        const Matrix<int>& r = t.getMatrix();
        CHECK(r.getRows() == 3);
        CHECK(r[1][0] == -9);
        CHECK(r[1][1] == 1);
    }
}

void runAllTests()
{
    testConstructors();
    testIndexOperator();
    testShift();
    testTask1();
    testTask2();
    std::cout << "Passed: " << passed << ", Failed: " << failed << '\n';
}

int main()
{
    runAllTests();
    return failed == 0 ? 0 : 1;
}
