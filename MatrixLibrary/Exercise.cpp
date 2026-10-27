#include "Exercise.h"
#include <utility>

miit::algebra::Exercise::Exercise(Matrix<int> matrix, Generator& generator)
    : matrix{ std::move(matrix) }, generator{ (generator) }
{
}

const miit::algebra::Matrix<int>& miit::algebra::Exercise::getMatrix() const
{
    return this->matrix;
}
