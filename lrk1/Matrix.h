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

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
};

#endif