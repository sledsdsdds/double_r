#pragma once
#include "Matrix.h"
#include <memory>

namespace miit::algebra
{
    /**
     * @brief базовый класс задания, агрегирующий матрицу и генератор
     */
    class Exercise
    {
    protected:
        Matrix<int> matrix;
        <Generator> generator;

    public:
        /**
         * @brief конструктор
         * @param matrix матрица
         * @param generator генератор
         */
        Exercise(Matrix<int> matrix, std::shared_ptr<Generator> generator);

        virtual ~Exercise() = default;

        /** @brief выыполнить задание */
        virtual void solve() = 0;

        /** @brief получить матрицу (только для чтения) */
        const Matrix<int>& getMatrix() const;
    };
}
