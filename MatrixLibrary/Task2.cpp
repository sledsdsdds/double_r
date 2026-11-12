#include "Task2.h"
#include <cstdlib>
#include <vector>
#include <algorithm>

miit::algebra::Task2::Task2(Matrix<int> matrix, Generator& generator)
    : Exercise(std::move(matrix), (generator))
{
}

void miit::algebra::Task2::solve()
{
    const std::size_t rows = this->matrix.getRows();
    const std::size_t cols = this->matrix.getCols();

    if (rows == 0 || cols == 0)
    {
        return;
    }

    // 1) Найти максимальный по модулю элемент.
    int maxAbs = std::abs(this->matrix[0][0]);
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < cols; ++j)
        {
            maxAbs = std::max(maxAbs, std::abs(this->matrix[i][j]));
        }
    }

    // 2) Сохранить копию первой строки.
    const std::vector<int> firstRow = this->matrix.getRow(0);

    // 3) Собрать индексы строк, содержащих maxAbs (до вставок!).
    std::vector<std::size_t> targetRows;
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < cols; ++j)
        {
            if (std::abs(this->matrix[i][j]) == maxAbs)
            {
                targetRows.push_back(i);
                break;
            }
        }
    }

    // 4) Вставлять с конца, чтобы индексы не сбивались.
    for (auto it = targetRows.rbegin(); it != targetRows.rend(); ++it)
    {
        this->matrix.insertRowAfter(*it + 1, firstRow);
    }
}
