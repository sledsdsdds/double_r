#include "Task1.h"

namespace miit::algebra
{
    Matrix Task1::solve()
    {
        Matrix result(source);
        const std::size_t rows = result.getRows();
        const std::size_t cols = result.getColumns();

        if (rows == 0 || cols == 0) return result;

        for (std::size_t j = 0; j < cols; ++j)
        {
            std::size_t maxRow = 0;
            for (std::size_t i = 1; i < rows; ++i)
            {
                if (result[i][j] > result[maxRow][j])
                    maxRow = i;
            }
            result[maxRow][j] = 0;
        }
        return result;
    }
}
