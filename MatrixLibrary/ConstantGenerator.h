#pragma once
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief генератор, возвращающий константное значение (в т.ч. 0)
     */
    class ConstantGenerator : public Generator
    {
    private:
        int value;

    public:
        /**
         * @brief конструктор генератора констант
         * @param value Значение, которое будет возвращаться
         */
        explicit ConstantGenerator(const int value);

        /**
         * @brief получить константное значение
         * @return заданная константа
         */
        int generate() override;
    };
}
