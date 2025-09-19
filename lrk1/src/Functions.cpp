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
