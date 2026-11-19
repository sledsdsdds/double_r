#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief здание 2: вставить первую строку после всех строк с максимальным по модулю элементом
     */
    class Task2 : public Exercise
    {
    public:
        /**
         * @brief конструктор
         * @param src ссылка на исходную матрицу
         */
        explicit Task2(Matrix& src) : Exercise(src) {}

        /**
         * @brief выполнить задание 1
         * @return измененная матрица
         */
        Matrix solve() override;
    };
}
