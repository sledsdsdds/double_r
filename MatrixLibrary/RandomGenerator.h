#pragma once
#include "Generator.h"
#include <random>

namespace miit::algebra
{
    /**
     * @brief генератор случайных чисел в диапазоне от min до max
     */
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;
        std::mt19937 generator;

    public:
        /**
         * @brief конструктор
         * @param min нижняя граница
         * @param max верхняя граница
         */
        RandomGenerator(const int min, const int max);

        int generate() override;
    };
}
