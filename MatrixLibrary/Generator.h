#pragma once

namespace miit::algebra
{
    /**
     * @brief абстрактный генератор значени
     */
    class Generator
    {
    public:
        virtual ~Generator() = default;

        /**
         * @brief сгенерировать очередное значение
         * @note метод не const, т.к. меняет внутреннее состояние генератора
         */
        virtual int generate() = 0;
    };
}
