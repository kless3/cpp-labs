#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    int **data;

public:
    explicit Matrix(int r = 0, int c = 0);

    [[maybe_unused]] Matrix(const Matrix &other);

    ~Matrix();

    [[nodiscard]] int getRows() const { return rows; }

    [[nodiscard]] int getCols() const { return cols; }

    void resize(int newRows, int newCols);

    void clear();

    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
        if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
            std::cout << "Error! Matrices should be equal size" << std::endl;
            exit(1);
        }

        Matrix result(lhs.rows, lhs.cols);
        for (auto i = 0; i < lhs.rows; i++) {
            for (auto j = 0; j < lhs.cols; j++) {
                result.data[i][j] = lhs.data[i][j] + rhs.data[i][j];
            }
        }
        return result;
    }

    Matrix &operator=(const Matrix &other);

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
        if (matrix.rows == 0 || matrix.cols == 0) {
            os << "Matrix is empty" << std::endl;
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

    friend std::istream &operator>>(std::istream &is, Matrix &matrix) {
        auto r = 0;
        auto c = 0;

        std::cout << "Enter amount of rows: ";
        is >> r;
        std::cout << "Enter amount of cols: ";
        is >> c;

        if (r <= 0 || c <= 0) {
            matrix.clear();
            std::cout << "Matrix is cleaned" << std::endl;
            return is;
        }

        matrix.resize(r, c);

        std::cout << "Enter element " << r << "x" << c << ":" << std::endl;
        for (auto i = 0; i < r; i++) {
            for (auto j = 0; j < c; j++) {
                std::cout << "Element [" << i << "][" << j << "]: ";
                is >> matrix.data[i][j];
            }
        }

        return is;
    }


};

#endif