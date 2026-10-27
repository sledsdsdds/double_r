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

/**
 * @brief Перечисление способов заполнения матрицы.
 * Используется для замены магических чисел в switch-case.
 */
enum class FillMode
{
    RANDOM = 1,   /**< случайные числа */
    KEYBOARD = 2, /**< ввод с клавиатуры */
    CONSTANT = 3, /**< константное значение */
    ZEROS = 4     /**< заполнение нулями */
};

namespace
{
    /**
     * @brief Безопасно считывает размер (число) из консоли.
     * @param prompt текст приглашения ко вводу
     * @return введенное число
     * @throws std::runtime_error если достигнут конец ввода (EOF)
     */
    std::size_t readSize(const std::string& prompt)
    {
        std::size_t value = 0;
        while (true)
        {
            std::cout << prompt;
            if (std::cin >> value) return value;
            if (std::cin.eof()) throw std::runtime_error("конец ввода");
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            std::cout << "гекорректный ввод, попробуйте снова.\n";
        }
    }

    /**
     * @brief Предлагает пользователю выбрать способ заполнения и создает соответствующий генератор.
     * @return указатель на созданный генератор (требует удаления через delete)
     */
    Generator* chooseGenerator()
    {
        std::cout << "\nВыберите способ заполнения:\n"
            << "  1 - случайные числа\n"
            << "  2 - ввод с клавиатуры\n"
            << "  3 - константное значение\n"
            << "  4 - нулями\n"
            << "Ваш выбор: ";

        int choice = 0;
        std::cin >> choice;

        switch (static_cast<FillMode>(choice))
        {
        case FillMode::RANDOM:
            return new RandomGenerator(-50, 50);
        case FillMode::KEYBOARD:
            return new IStreamGenerator(std::cin);
        case FillMode::CONSTANT:
        {
            int c = 0;
            std::cout << "введите константу: ";
            std::cin >> c;
            return new ConstantGenerator(c);
        }
        case FillMode::ZEROS:
            return new ConstantGenerator(0);
        default:
            std::cout << "неверный выбор, используется RandomGenerator.\n";
            return new RandomGenerator(-50, 50);
        }
    }
}

/**
 * @brief Точка входа в демонстрационную программу.
 * @return 0 при успешном выполнении, 1 при возникновении ошибки
 */
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "Russian");

    try
    {
        const std::size_t rows = readSize("Введите количество строк n: ");
        const std::size_t cols = readSize("Введите количество столбцов m: ");

        Generator* generator = chooseGenerator();
        Matrix<int> original(rows, cols, *generator);

        std::cout << "\nИсходная матрица:\n" << original.toString();

        //задание 1
        {
            Task1 task1(original, *generator);
            task1.solve();
            std::cout << "\nЗадание 1 (макс. элемент каждого столбца -> 0):\n"
                << task1.getMatrix().toString();
        }

        //задание 2
        {
            Task2 task2(original, *generator);
            task2.solve();
            std::cout << "\nЗадание 2 (вставка первой строки после строк с max|elem|):\n"
                << task2.getMatrix().toString();
        }

        //демонстрация операторов
        std::cout << "\nСдвиг влево на 2 (operator<<):\n";
        Matrix<int> shifted = original;
        shifted << 2;
        std::cout << shifted.toString();

        std::cout << "\nСдвиг вправо на 1 (operator>>):\n";
        Matrix<int> shifted2 = original;
        shifted2 >> 1;
        std::cout << shifted2.toString();

        std::cout << "\nЭлемент [0][0] через operator[]: " << original[0][0] << '\n';

        delete generator; //очищаем память, выделенную под генератор
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Ошибка: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
