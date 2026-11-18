#pragma once

namespace miit::algebra
{
    /**
     * @brief абстрактный генератор значени
     */
    class Generator
    {
    public:
        /** @brief конструктор по умолчанию */
        Generator() = default;

        /** @brief Виртуальный деструктор */
        virtual ~Generator() = default;

        /**
         * @brief сгенерировать очередное значение
         * @return сгенерированное целое число
         */
        virtual int generate() = 0;
    };
}
