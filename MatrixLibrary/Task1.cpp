#include "Task1.h"

miit::algebra::Task1::Task1(Matrix<int> matrix, Generator& generator)
    : Exercise(std::move(matrix), (generator))
{
}

void miit::algebra::Task1::solve()
{
    const std::size_t rows = this->matrix.getRows();
    const std::size_t cols = this->matrix.getCols();

    if (rows == 0 || cols == 0)
    {
        return;
    }

    for (std::size_t j = 0; j < cols; ++j)
    {
        std::size_t maxRow = 0;
        for (std::size_t i = 1; i < rows; ++i)
        {
            if (this->matrix[i][j] > this->matrix[maxRow][j])
            {
                maxRow = i;
            }
        }
        this->matrix[maxRow][j] = 0;
    }
}
