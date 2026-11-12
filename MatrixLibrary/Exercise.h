#pragma once
#include "Matrix.h"

namespace miit::algebra
{
    /**
     * @brief базовый класс задания, агрегирующий матрицу и генератор
     */
    class Exercise
    {
    protected:
        Matrix<int> matrix;
        Generator& generator;

    public:
        /**
         * @brief конструктор
         * @param matrix матрица
         * @param generator генератор
         */
        Exercise(Matrix<int> matrix, Generator& generator);

        virtual ~Exercise() = default;

        /** @brief выполнить задание */
        virtual void solve() = 0;

        /** @brief Получить матрицу (только для чтения) */
        const Matrix<int>& getMatrix() const;
    };
}
