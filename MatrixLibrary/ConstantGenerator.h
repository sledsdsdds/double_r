#pragma once
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief генератор, возвращающий константное значение (в т.ч. 0).
     */
    class ConstantGenerator : public Generator
    {
    private:
        int value;

    public:
        explicit ConstantGenerator(const int value);

        int generate() override;
    };
}
