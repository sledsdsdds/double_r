#include <windows.h>
#include <iostream>
#include <memory>
#include <limits>
#include <string>
#include <stdexcept>
#include <clocale>

#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConstantGenerator.h"
#include "Task1.h"
#include "Task2.h"

using namespace miit::algebra;

namespace
{
    std::size_t readSize(const std::string& prompt)
    {
        std::size_t value = 0;
        while (true)
        {
            std::cout << prompt;
            if (std::cin >> value)
            {
                return value;
            }
            if (std::cin.eof())
            {
                throw std::runtime_error("конец ввода");
            }
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            std::cout << "некорректный ввод, попробуйте снова!\n";
        }
    }

    std::shared_ptr<Generator> chooseGenerator()
    {
        std::cout << "\nвыберите способ заполнения:\n"
            << "  1 - случайные числа\n"
            << "  2 - ввод с клавиатуры\n"
            << "  3 - константное значение\n"
            << "  4 - нулями\n"
            << "ваш выбор: ";

        int choice = 0;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            return std::make_shared<RandomGenerator>(-50, 50);
        case 2:
            return std::make_shared<IStreamGenerator>(std::cin);
        case 3:
        {
            int c = 0;
            std::cout << "введите константу: ";
            std::cin >> c;
            return std::make_shared<ConstantGenerator>(c);
        }
        case 4:
            return std::make_shared<ConstantGenerator>(0);
        default:
            std::cout << "неверный выбор, используется RandomGenerator.\n";
            return std::make_shared<RandomGenerator>(-50, 50);
        }
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "Russian");

    try
    {
        const std::size_t rows = readSize("введите количество строк n: ");
        const std::size_t cols = readSize("введите количество столбцов m: ");

        auto generator = chooseGenerator();

        Matrix<int> original(rows, cols, *generator);

        std::cout << "\nисходная матрица:\n" << original.toString();

        // задание2
        {
            Task1 task1(original, generator);
            task1.solve();
            std::cout << "\nзадание 1 (макс. элемент каждого столбца -> 0):\n"
                << task1.getMatrix().toString();
        }

        // здаание2
        {
            Task2 task2(original, generator);
            task2.solve();
            std::cout << "\nзадание 2 (вставка первой строки после строк с max|elem|):\n"
                << task2.getMatrix().toString();
        }

        //  демонстрация операторов 
        std::cout << "\nсдвиг влево на 2 (operator<<):\n";
        Matrix<int> shifted = original;
        shifted << 2;
        std::cout << shifted.toString();

        std::cout << "\nсдвиг вправо на 1 (operator>>):\n";
        Matrix<int> shifted2 = original;
        shifted2 >> 1;
        std::cout << shifted2.toString();

        std::cout << "\nэлемент [0][0] через operator[]: " << original[0][0] << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cerr << "ошибка: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
