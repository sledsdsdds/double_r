#pragma once
#include "Matrix.h"

namespace miit::algebra
{
    /**
     * @brief базовый класс для выполнения заданий над матрицей
     */
    class Exercise
    {
    protected:
        Matrix& source;

    public:
        /**
         * @brief конструктор базового класса
         * @param src ссылка на исходную матрицу
         */
        explicit Exercise(Matrix& src) : source(src) {}

        /** @brief виртуальный деструктор */
        virtual ~Exercise() = default;

        /**
         * @brief выполнить задание
         * @return новая матрица с результатом
         */
        virtual Matrix solve() { return source; }
    };
}
