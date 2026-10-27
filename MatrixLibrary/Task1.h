#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief задание 1: заменить максимальный элемент каждого столбца нулём
     */
    class Task1 : public Exercise
    {
    public:
        Task1(Matrix<int> matrix, Generator& generator);

        void solve() override;
    };
}
