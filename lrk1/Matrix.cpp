#include "Matrix.h"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (rows > 0 && cols > 0) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols]();
        }
    } else {
        data = nullptr;
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    if (rows > 0 && cols > 0) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    } else {
        data = nullptr;
    }
}

Matrix::~Matrix() {
    clear();
}

void Matrix::clear() {
    if (data) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
    rows = 0;
    cols = 0;
}

void Matrix::resize(int newRows, int newCols) {
    if (newRows <= 0 || newCols <= 0) {
        clear();
        return;
    }

    int** newData = new int*[newRows];
    for (int i = 0; i < newRows; i++) {
        newData[i] = new int[newCols]();
    }

    if (data) {
        int copyRows = (rows < newRows) ? rows : newRows;
        int copyCols = (cols < newCols) ? cols : newCols;

        for (int i = 0; i < copyRows; i++) {
            for (int j = 0; j < copyCols; j++) {
                newData[i][j] = data[i][j];
            }
        }

        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    data = newData;
    rows = newRows;
    cols = newCols;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
        throw std::invalid_argument("Матрицы должны быть одинакового размера для сложения");
    }

    Matrix result(lhs.rows, lhs.cols);
    for (int i = 0; i < lhs.rows; i++) {
        for (int j = 0; j < lhs.cols; j++) {
            result.data[i][j] = lhs.data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    clear();

    rows = other.rows;
    cols = other.cols;

    if (rows > 0 && cols > 0) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
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

std::istream& operator>>(std::istream& is, Matrix& matrix) {
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