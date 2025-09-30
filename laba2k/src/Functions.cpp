#include "../include/Functions.h"
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}



void addMatrices(Matrix &matrix1, Matrix &matrix2, Matrix &result) {
    Matrix::setAutoSize(false);
    cin >> matrix1;

    if (matrix1.getRows() == 0 || matrix1.getCols() == 0) {
        cout << "Error: first matrix is empty!" << endl;
        return;
    }

    Matrix::setAutoSize(true);
    matrix2.resize(matrix1.getRows(), matrix1.getCols());
    cout << "Second matrix size automatically set to " << matrix1.getRows()
         << "x" << matrix1.getCols() << endl;
    cin >> matrix2;

    Matrix::setAutoSize(false);

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