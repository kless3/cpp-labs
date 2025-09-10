#include "Matrix.h"
#include <iostream>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showMatrixInfo(const Matrix& matrix, const string& name) {
    cout << name << " �������: " << matrix.getRows() << "x" << matrix.getCols() << endl;
    if (matrix.getRows() > 0 && matrix.getCols() > 0) {
        cout << matrix;
    } else {
        cout << "������� �����" << endl;
    }
}

int main() {
    int choice;
    Matrix matrix1;
    Matrix matrix2;
    Matrix result;

    do {
        cout << "1. ������/�������� ������ �������" << endl;
        cout << "2. ������/�������� ������ �������" << endl;
        cout << "3. �������� ������ �������" << endl;
        cout << "4. �������� ������ �������" << endl;
        cout << "5. �������� �������" << endl;
        cout << "6. ������� �������" << endl;
        cout << "7. �������� ��������� ��������" << endl;
        cout << "8. �������� ���������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "������ �����! ������� �����." << endl;
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: {
                cin >> matrix1;
                cout << "������ ������� �����������:" << endl;
                showMatrixInfo(matrix1, "������");
                break;
            }
            case 2: {
                cin >> matrix2;
                cout << "������ ������� �����������:" << endl;
                showMatrixInfo(matrix2, "������");
                break;
            }
            case 3: {
                matrix1.clear();
                cout << "������ ������� �������" << endl;
                break;
            }
            case 4: {
                matrix2.clear();
                cout << "������ ������� �������" << endl;
                break;
            }
            case 5: {
                showMatrixInfo(matrix1, "������");
                showMatrixInfo(matrix2, "������");
                break;
            }
            case 6: {
                if (matrix1.getRows() == 0 || matrix1.getCols() == 0 ||
                    matrix2.getRows() == 0 || matrix2.getCols() == 0) {
                    cout << "������: ���� ��� ��� ������� �����!" << endl;
                    break;
                }
                try {
                    result = matrix1 + matrix2;
                    cout << "�������� ��������� �������!" << endl;
                    cout << "������ ����������: " << result.getRows() << "x" << result.getCols() << endl;
                } catch (const exception& e) {
                    cout << "������: " << e.what() << endl;
                }
                break;
            }
            case 7: {
                if (result.getRows() > 0 && result.getCols() > 0) {
                    cout << "��������� (" << result.getRows() << "x" << result.getCols() << "):" << endl;
                    cout << result;
                } else {
                    cout << "��������� ��� �� �������� ��� ����" << endl;
                }
                break;
            }
            case 8: {
                result.clear();
                cout << "��������� ������" << endl;
                break;
            }
            case 0: {
                cout << "����� �� ���������..." << endl;
                break;
            }
            default: {
                cout << "�������� �����! ���������� �����." << endl;
                break;
            }
        }

        if (choice != 0) {
            cout << "\n������� Enter ��� �����������...";
            cin.get();
        }

    } while (choice != 0);

    return 0;
}