#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    explicit Matrix(int r = 0, int c = 0);
    Matrix(const Matrix& other);
    ~Matrix();

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void resize(int newRows, int newCols);
    void clear();

    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
        if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
            throw std::invalid_argument("Матрицы должны быть одинакового размера для сложения");
        }

        Matrix result(lhs.rows, lhs.cols);
        for (auto i = 0; i < lhs.rows; i++) {
            for (auto j = 0; j < lhs.cols; j++) {
                result.data[i][j] = lhs.data[i][j] + rhs.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator=(const Matrix& other);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        if (matrix.rows == 0 || matrix.cols == 0) {
            os << "Матрица пуста" << std::endl;
            return os;
        }

        for (auto i = 0; i < matrix.rows; i++) {
            for (auto j = 0; j < matrix.cols; j++) {
                os << matrix.data[i][j] << "\t";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        auto r = 0;
        auto c = 0;

        std::cout << "Введите количество строк: ";
        is >> r;
        std::cout << "Введите количество столбцов: ";
        is >> c;

        if (r <= 0 || c <= 0) {
            matrix.clear();
            std::cout << "Матрица очищена" << std::endl;
            return is;
        }

        matrix.resize(r, c);

        std::cout << "Введите элементы матрицы " << r << "x" << c << ":" << std::endl;
        for (auto i = 0; i < r; i++) {
            for (auto j = 0; j < c; j++) {
                std::cout << "Элемент [" << i << "][" << j << "]: ";
                is >> matrix.data[i][j];
            }
        }

        return is;
    }
};

#endif