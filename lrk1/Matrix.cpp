#include "Matrix.h"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (rows > 0 && cols > 0) {
        data = new int*[rows];
        for (auto i = 0; i < rows; i++) {
            data[i] = new int[cols]();
        }
    } else {
        data = nullptr;
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    if (rows > 0 && cols > 0) {
        data = new int*[rows];
        for (auto i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (auto j = 0; j < cols; j++) {
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
        for (auto i = 0; i < rows; i++) {
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

    auto newData = new int*[newRows];
    for (auto i = 0; i < newRows; i++) {
        newData[i] = new int[newCols]();
    }

    if (data) {
        auto copyRows = (rows < newRows) ? rows : newRows;
        auto copyCols = (cols < newCols) ? cols : newCols;

        for (auto i = 0; i < copyRows; i++) {
            for (auto j = 0; j < copyCols; j++) {
                newData[i][j] = data[i][j];
            }
        }

        for (auto i = 0; i < rows; i++) {
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
        throw std::invalid_argument("������� ������ ���� ����������� ������� ��� ��������");
    }

    Matrix result(lhs.rows, lhs.cols);
    for (auto i = 0; i < lhs.rows; i++) {
        for (auto j = 0; j < lhs.cols; j++) {
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
        for (auto i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (auto j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    return *this;
}