#pragma once
#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /**
     * @brief генератор, считывающий значения из потока ввода
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;

    public:
        /**
         * @brief конструктор генератора ввода
         * @param in поток ввода (по умолчанию std::cin)
         */
        IStreamGenerator(std::istream& in = std::cin);

        /**
         * @brief считать очередное число из потока
         * @return считанное целое число
         */
        int generate() override;
    };
}
