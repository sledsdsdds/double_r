#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief класс для работы с двумерной матрицей (на основе std::vector)
     */
    class Matrix
    {
    private:
        size_t rows;
        size_t columns;
        std::vector<std::vector<int>> data;

    public:
        /** @brief конструктор по умолчанию (создает пустую матрицу 0x0) */
        Matrix() : rows(0), columns(0) {}

        /**
         * @brief конструктор с параметрами (заполняет нулями)
         * @param r количество строк
         * @param c количество столбцов
         */
        Matrix(const size_t r, const size_t c) : rows(r), columns(c), data(r, std::vector<int>(c, 0)) {}

        /** @brief конструктор копирования */
        Matrix(const Matrix& other) = default;
        /** @brief конструктор перемещения */
        Matrix(Matrix&& other) noexcept = default;
        /** @brief деструктор */
        ~Matrix() = default;
        /** @brief оператор присваивания копированием */
        Matrix& operator=(const Matrix& other) = default;
        /** @brief оператор присваивания перемещением */
        Matrix& operator=(Matrix&& other) noexcept = default;

        /**
         * @brief оператор сравнения на равенство
         * @param other другая матрица
         * @return true, если размеры и элементы совпадают
         */
        bool operator==(const Matrix& other) const { return data == other.data; }

        /**
         * @brief оператор сравнения на неравенство
         * @param other другая матрица
         * @return true, если матрицы различаются
         */
        bool operator!=(const Matrix& other) const { return !(*this == other); }

        /**
         * @brief доступ к строке по индексу (изменяемый)
         * @param index индекс строки
         * @return ссылка на вектор строки
         */
        std::vector<int>& operator[](const size_t index) { return data.at(index); }

        /**
         * @brief доступ к строке по индексу (только для чтения)
         * @param index индекс строки
         * @return константная ссылка на вектор строки
         */
        const std::vector<int>& operator[](const size_t index) const { return data.at(index); }

        /** @brief получить количество строк */
        size_t getRows() const { return rows; }

        /** @brief получить количество столбцов */
        size_t getColumns() const { return columns; }

        /**
         * @brief заполнить матрицу значениями с помощью генератора
         * @param generator ссылка на генератор
         */
        void fillArray(const Generator& generator)
        {
            for (size_t i = 0; i < rows; ++i)
                for (size_t j = 0; j < columns; ++j)
                    data[i][j] = const_cast<Generator&>(generator).generate();
        }

        /**
         * @brief получить строковое представление матрицы
         * @return строка с элементами матрицы
         */
        std::string toString() const
        {
            std::ostringstream oss;
            for (const auto& row : data)
            {
                for (int el : row) oss << el << ' ';
                oss << '\n';
            }
            return oss.str();
        }

        /**
         * @brief вставить строку после указанного индекса
         * @param rowIndex индекс строки, после которой вставляем
         * @param newRow вектор новой строки
         * @throws std::out_of_range если индекс выходит за пределы
         */
        void insertRowAfter(const size_t rowIndex, const std::vector<int>& newRow)
        {
            if (rowIndex >= rows) throw std::out_of_range("insertRowAfter: index out of range");
            data.insert(data.begin() + rowIndex + 1, newRow);
            rows++;
        }

        /**
         * @brief циклический сдвиг каждой строки влево
         * @param shift величина сдвига
         * @return Ссылка на текущую матрицу
         */
        Matrix& operator<<(const size_t shift)
        {
            if (rows == 0 || columns == 0) return *this;
            size_t s = shift % columns;
            for (auto& row : data) std::rotate(row.begin(), row.begin() + s, row.end());
            return *this;
        }

        /**
         * @brief циклический сдвиг каждой строки вправо
         * @param shift величина сдвига
         * @return ссылка на текущую матрицу
         */
        Matrix& operator>>(const size_t shift)
        {
            if (rows == 0 || columns == 0) return *this;
            size_t s = shift % columns;
            for (auto& row : data) std::rotate(row.rbegin(), row.rbegin() + s, row.rend());
            return *this;
        }

        /** @brief оператор вывода в поток (для тестов) */
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
        {
            os << matrix.toString();
            return os;
        }

        /** @brief оператор ввода из потока */
        friend std::istream& operator>>(std::istream& is, Matrix& matrix)
        {
            for (size_t i = 0; i < matrix.rows; ++i)
                for (size_t j = 0; j < matrix.columns; ++j)
                    is >> matrix.data[i][j];
            return is;
        }
    };
}
