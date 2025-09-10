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

    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator=(const Matrix& other);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        if (matrix.rows == 0 || matrix.cols == 0) {
            os << "Матрица пуста" << std::endl;
            return os;
        }

        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                os << matrix.data[i][j] << "\t";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        int r;
        int c;

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
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                std::cout << "Элемент [" << i << "][" << j << "]: ";
                is >> matrix.data[i][j];
            }
        }

        return is;
    }
};

#endif