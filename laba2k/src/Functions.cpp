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


void enterFirstMatrix(Matrix& matrix1) {
    cin >> matrix1;
    cout << "First matrix set:" << endl;
    showMatrixInfo(matrix1, "First");
}

void enterSecondMatrix(Matrix& matrix2) {
    cin >> matrix2;
    cout << "Second matrix set:" << endl;
    showMatrixInfo(matrix2, "Second");
}

void clearFirstMatrix(Matrix& matrix1) {
    matrix1.clear();
    cout << "First matrix cleared" << endl;
}

void clearSecondMatrix(Matrix& matrix2) {
    matrix2.clear();
    cout << "Second matrix cleared" << endl;
}

void showMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    showMatrixInfo(matrix1, "First");
    showMatrixInfo(matrix2, "Second");
}

void addMatrices(const Matrix& matrix1, const Matrix& matrix2, Matrix& result) {
    if (matrix1.getRows() == 0 || matrix1.getCols() == 0 ||
        matrix2.getRows() == 0 || matrix2.getCols() == 0) {
        cout << "Error: one or both matrices are empty!" << endl;
        return;
    }
    try {
        result = matrix1 + matrix2;
        cout << "Addition completed successfully!" << endl;
        cout << "Result size: " << result.getRows() << "x" << result.getCols() << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void showResult(const Matrix& result) {
    if (result.getRows() > 0 && result.getCols() > 0) {
        cout << "Result (" << result.getRows() << "x" << result.getCols() << "):" << endl;
        cout << result;
    } else {
        cout << "Result not yet calculated or empty" << endl;
    }
}

void clearResult(Matrix& result) {
    result.clear();
    cout << "Result cleared" << endl;
}
