#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief задание 1: заменить максимальный элемент каждого столбца нулем
     */
    class Task1 : public Exercise
    {
    public:
        /**
         * @brief конструктор
         * @param src ссылка на исходную матрицу
         */
        explicit Task1(Matrix& src) : Exercise(src) {}

        /**
         * @brief выполнить задание 1
         * @return атрица с замененными максимумами
         */
        Matrix solve() override;
    };
}
