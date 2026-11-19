#include "Task2.h"
#include <cstdlib>
#include <vector>
#include <algorithm>

namespace miit::algebra
{
    Matrix Task2::solve()
    {
        Matrix result(source);
        const std::size_t rows = result.getRows();
        const std::size_t cols = result.getColumns();

        if (rows == 0 || cols == 0) return result;

        int maxAbs = std::abs(result[0][0]);
        for (std::size_t i = 0; i < rows; ++i)
            for (std::size_t j = 0; j < cols; ++j)
                maxAbs = std::max(maxAbs, std::abs(result[i][j]));

        const std::vector<int> firstRow = result[0];

        std::vector<std::size_t> targetRows;
        for (std::size_t i = 0; i < rows; ++i)
        {
            for (std::size_t j = 0; j < cols; ++j)
            {
                if (std::abs(result[i][j]) == maxAbs)
                {
                    targetRows.push_back(i);
                    break;
                }
            }
        }

        for (auto it = targetRows.rbegin(); it != targetRows.rend(); ++it)
            result.insertRowAfter(*it, firstRow);

        return result;
    }
}
