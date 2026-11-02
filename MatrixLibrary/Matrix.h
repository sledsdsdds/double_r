#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cstddef>

#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief шаблонный класс двумерного массива (матрицы)
     * @tparam T тип хранимых элементов
     *
     * @note реализация шаблона полностью находится в заголовочном файле, т.к. компилятор должен видеть её при инстанцировании
     */
    template <typename T>
    class Matrix
    {
    private:
        std::vector<std::vector<T>> data;
        std::size_t rows;
        std::size_t cols;

    public:
        /** @brief конструктор по умолчанию */
        Matrix();

        /**
         * @brief конструктор с размерами (заполняет значениями по умолчанию)
         * @param rows число строк
         * @param cols число столбцов
         */
        Matrix(const std::size_t rows, std::size_t cols);

        /**
         * @brief конструктор с размерами и генератором
         * @param rows число строк
         * @param cols число столбцов
         * @param generator генератор значений (меняется при заполнении)
         */
        Matrix(const std::size_t rows, std::size_t cols, Generator& generator);

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
         * @brief Оператор сравнения на равенство
         * @param other другая матрица для сравнения
         * @return true, если матрицы имеют одинаковый размер и одинаковые элементы
         */
        bool operator==(const Matrix& other) const;

        /**
         * @brief Оператор сравнения на неравенство
         * @param other другая матрица для сравнения
         * @return true, если матрицы различаются по размеру или элементам
         */
        bool operator!=(const Matrix& other) const;

        /**
         * @brief циклический сдвиг элементов каждой строки влево
         * @param shift величина сдвига
         * @return ссылка на текущий объект
         */
        Matrix& operator<<(const std::size_t shift);

        /**
         * @brief циклический сдвиг элементов каждой строки вправо
         * @param shift величина сдвига
         * @return ссылка на текущий объект
         */
        Matrix& operator>>(const std::size_t shift);

        /**
         * @brief доступ к строке по индексу (изменяемый)
         * @param index индекс строки
         */
        std::vector<T>& operator[](const std::size_t index);

        /**
         * @brief доступ к строке по индексу (только для чтения)
         * @param index индекс строки
         */
        const std::vector<T>& operator[](const std::size_t index) const;

        /** @brief количество строк */
        std::size_t getRows() const noexcept;

        /** @brief количество столбцов */
        std::size_t getCols() const noexcept;

        /** @brief признак пустой матрицы */
        bool empty() const noexcept;

        /** @brief Строковое представление матрицы */
        std::string toString() const;

        /**
         * @brief заполнить матрицу значениями из генератора
         * @param generator генератор значений
         */
        void fill(Generator& generator);

        /**
         * @brief вставить строку после указанной позиции
         * @param pos позиция (0..rows), после которой вставить
         * @param row вставляемая строка
         */
        void insertRowAfter(const std::size_t pos, const std::vector<T>& row);

        /**
         * @brief получить строку по индексу (изменяемую)
         * @param index индекс строки
         */
        std::vector<T>& getRow(const std::size_t index);

        /**
         * @brief получить строку по индексу (только для чтения)
         * @param index индекс строки
         */
        const std::vector<T>& getRow(const std::size_t index) const;
    };

    // ==================== Реализация ====================

    template <typename T>
    Matrix<T>::Matrix()
        : rows(0), cols(0)
    {
    }

    template <typename T>
    Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
        : data(rows, std::vector<T>(cols, T{})), rows(rows), cols(cols)
    {
    }

    template <typename T>
    Matrix<T>::Matrix(std::size_t rows, std::size_t cols, Generator& generator)
        : data(rows, std::vector<T>(cols, T{})), rows(rows), cols(cols)
    {
        fill(generator);
    }

    template <typename T>
    bool Matrix<T>::operator==(const Matrix& other) const
    {
        return data == other.data; // std::vector сам умеет сравнивать свои элементы
    }

    template <typename T>
    bool Matrix<T>::operator!=(const Matrix& other) const
    {
        return !(*this == other);
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator<<(std::size_t shift)
    {
        if (rows == 0 || cols == 0)
        {
            return *this;
        }
        shift %= cols;
        for (auto& row : data)
        {
            std::rotate(row.begin(), row.begin() + shift, row.end());
        }
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator>>(std::size_t shift)
    {
        if (rows == 0 || cols == 0)
        {
            return *this;
        }
        shift %= cols;
        for (auto& row : data)
        {
            std::rotate(row.rbegin(), row.rbegin() + shift, row.rend());
        }
        return *this;
    }

    template <typename T>
    std::vector<T>& Matrix<T>::operator[](std::size_t index)
    {
        return data.at(index);
    }

    template <typename T>
    const std::vector<T>& Matrix<T>::operator[](std::size_t index) const
    {
        return data.at(index);
    }

    template <typename T>
    std::size_t Matrix<T>::getRows() const noexcept
    {
        return rows;
    }

    template <typename T>
    std::size_t Matrix<T>::getCols() const noexcept
    {
        return cols;
    }

    template <typename T>
    bool Matrix<T>::empty() const noexcept
    {
        return rows == 0 || cols == 0;
    }

    template <typename T>
    std::string Matrix<T>::toString() const
    {
        std::ostringstream oss;
        for (const auto& row : data)
        {
            for (const auto& el : row)
            {
                oss << el << ' ';
            }
            oss << '\n';
        }
        return oss.str();
    }

    template <typename T>
    void Matrix<T>::fill(Generator& generator)
    {
        for (auto& row : data)
        {
            for (auto& el : row)
            {
                el = static_cast<T>(generator.generate());
            }
        }
    }

    template <typename T>
    void Matrix<T>::insertRowAfter(std::size_t pos, const std::vector<T>& row)
    {
        if (pos > rows)
        {
            throw std::out_of_range("insertRowAfter: pos > rows");
        }
        data.insert(data.begin() + static_cast<std::ptrdiff_t>(pos), row);
        ++rows;
    }

    template <typename T>
    std::vector<T>& Matrix<T>::getRow(std::size_t index)
    {
        return data.at(index);
    }

    template <typename T>
    const std::vector<T>& Matrix<T>::getRow(std::size_t index) const
    {
        return data.at(index);
    }
}
