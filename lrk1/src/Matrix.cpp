#include "../include/Matrix.h"
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