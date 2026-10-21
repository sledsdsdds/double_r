#include "Exercise.h"
#include <utility>

miit::algebra::Exercise::Exercise(Matrix<int> matrix, std::shared_ptr<Generator> generator)
    : matrix{ std::move(matrix) }, generator{ std::move(generator) }
{
}

const miit::algebra::Matrix<int>& miit::algebra::Exercise::getMatrix() const
{
    return this->matrix;
}
