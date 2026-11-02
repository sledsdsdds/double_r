#pragma once
#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /**
     * @brief генератор, читающий значения из потока ввода
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;

    public:
        /**
         * @brief конструктор
         * @param in поток ввода (по умолчанию std::cin)
         */
        IStreamGenerator(std::istream& in = std::cin);

        int generate() override;
    };
}
