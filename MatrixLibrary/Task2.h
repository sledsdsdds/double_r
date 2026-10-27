#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief задание 2: после всех строк, содержащих максимальный по модулю элемент, вставить первую строку
     */
    class Task2 : public Exercise
    {
    public:
        Task2(Matrix<int> matrix, Generator& generator);

        void solve() override;
    };
}
