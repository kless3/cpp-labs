#include "../include/Functions.h"

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

void showMatrixInfo(const Matrix &matrix, const string &name) {
    cout << name << " matrix: " << matrix.getRows() << "x" << matrix.getCols() << endl;
    if (matrix.getRows() > 0 && matrix.getCols() > 0) {
        cout << matrix;
    } else {
        cout << "Matrix is empty" << endl;
    }
}

void enterMatrices(Matrix &matrix1, Matrix &matrix2) {

    auto r = 0;
    auto c = 0;

    cout << "Enter amount of rows: ";
    cin >> r;
    cout << "Enter amount of cols: ";
    cin >> c;

    if (r <= 0 || c <= 0) {
        matrix1.clear();
        matrix2.clear();
        cout << "Matrices are cleaned" << endl;
        return;
    }

    matrix1.resize(r, c);
    matrix2.resize(r, c);

    cout << "\nEnter elements for first matrix " << r << "x" << c << ":" << endl;
    for (auto i = 0; i < r; i++) {
        for (auto j = 0; j < c; j++) {
            cout << "First matrix [" << i << "][" << j << "]: ";
            cin >> matrix1.data[i][j];
        }
    }

    cout << "\nEnter elements for second matrix " << r << "x" << c << ":" << endl;
    for (auto i = 0; i < r; i++) {
        for (auto j = 0; j < c; j++) {
            cout << "Second matrix [" << i << "][" << j << "]: ";
            cin >> matrix2.data[i][j];
        }
    }

    cout << "\nMatrices set successfully!" << endl;
    cout << "First matrix:" << endl;
    showMatrixInfo(matrix1, "First");
    cout << "Second matrix:" << endl;
    showMatrixInfo(matrix2, "Second");
}

void addMatrices(const Matrix &matrix1, const Matrix &matrix2, Matrix &result) {
    if (matrix1.getRows() == 0 || matrix1.getCols() == 0 ||
        matrix2.getRows() == 0 || matrix2.getCols() == 0) {
        cout << "Error: one or both matrices are empty!" << endl;
        return;
    }

    if (matrix1.getRows() != matrix2.getRows() || matrix1.getCols() != matrix2.getCols()) {
        cout << "Error: matrices have different dimensions!" << endl;
        return;
    }

    result = matrix1 + matrix2;
    cout << "Addition completed successfully!" << endl;
}

void showResult(const Matrix &result) {
    if (result.getRows() > 0 && result.getCols() > 0) {
        cout << "Result (" << result.getRows() << "x" << result.getCols() << "):" << endl;
        cout << result;
    } else {
        cout << "Result not yet calculated or empty" << endl;
    }
}