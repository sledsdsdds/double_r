#include <windows.h>
#include <iostream>
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

enum FillMode { RANDOM = 1, KEYBOARD = 2, CONSTANT = 3, ZEROS = 4 };

namespace
{
    std::size_t readSize(const std::string& prompt)
    {
        std::size_t value = 0;
        while (true)
        {
            std::cout << prompt;
            if (std::cin >> value) return value;
            if (std::cin.eof()) throw std::runtime_error("Конец ввода");
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            std::cout << "Некорректный ввод, попробуйте снова.\n";
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
        const std::size_t rows = readSize("Введите количество строк n: ");
        const std::size_t cols = readSize("Введите количество столбцов m: ");

        Matrix original(rows, cols);

        std::cout << "\nВыберите способ заполнения:\n"
            << "  " << RANDOM << " - случайные числа\n"
            << "  " << KEYBOARD << " - ввод с клавиатуры\n"
            << "  " << CONSTANT << " - константное значение\n"
            << "  " << ZEROS << " - нулями\n"
            << "Ваш выбор: ";

        int choice = 0;
        std::cin >> choice;

        switch (choice)
        {
        case RANDOM:
        {
            int minVal = 0, maxVal = 0;
            std::cout << "Введите минимум диапазона: ";
            std::cin >> minVal;
            std::cout << "Введите максимум диапазона: ";
            std::cin >> maxVal;
            
            RandomGenerator gen(minVal, maxVal);
            original.fillArray(gen);
            break;
        }
        case KEYBOARD:
        {
            IStreamGenerator gen(std::cin);
            original.fillArray(gen);
            break;
        }
        case CONSTANT:
        {
            int c = 0;
            std::cout << "Введите константу: ";
            std::cin >> c;
            ConstantGenerator gen(c);
            original.fillArray(gen);
            break;
        }
        case ZEROS:
        {
            ConstantGenerator gen(0);
            original.fillArray(gen);
            break;
        }
        default:
        {
            std::cout << "Неверный выбор. Заполняем нулями.\n";
            ConstantGenerator gen(0);
            original.fillArray(gen);
            break;
        }
        }

        std::cout << "\nИсходная матрица:\n" << original.toString();

        Task1 task1(original);
        Matrix result1 = task1.solve();
        std::cout << "\nЗадание 1 (макс. элемент каждого столбца -> 0):\n" << result1.toString();

        Task2 task2(original);
        Matrix result2 = task2.solve();
        std::cout << "\nЗадание 2 (вставка первой строки после строк с max|elem|):\n" << result2.toString();

        std::cout << "\nСдвиг влево на 2:\n";
        Matrix shifted = original;
        shifted << 2;
        std::cout << shifted.toString();

        std::cout << "\nСдвиг вправо на 1:\n";
        Matrix shifted2 = original;
        shifted2 >> 1;
        std::cout << shifted2.toString();

        std::cout << "\nЭлемент [0][0]: " << original[0][0] << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Ошибка: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
