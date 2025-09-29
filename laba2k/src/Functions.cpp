#include "../include/Functions.h"

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

void addMatrices(Matrix &matrix1, Matrix &matrix2, Matrix &result) {
    cin >> matrix1;
    cin >> matrix2;

    if (matrix1.getRows() == 0 || matrix1.getCols() == 0 ||
        matrix2.getRows() == 0 || matrix2.getCols() == 0) {
        cout << "Error: one or both matrices are empty!" << endl;
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