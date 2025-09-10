#include "Matrix.h"
#include <iostream>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showMatrixInfo(const Matrix& matrix, const string& name) {
    cout << name << " матрица: " << matrix.getRows() << "x" << matrix.getCols() << endl;
    if (matrix.getRows() > 0 && matrix.getCols() > 0) {
        cout << matrix;
    } else {
        cout << "Матрица пуста" << endl;
    }
}

int main() {
    int choice;
    Matrix matrix1;
    Matrix matrix2;
    Matrix result;

    do {
        cout << "1. Ввести/изменить первую матрицу" << endl;
        cout << "2. Ввести/изменить вторую матрицу" << endl;
        cout << "3. Очистить первую матрицу" << endl;
        cout << "4. Очистить вторую матрицу" << endl;
        cout << "5. Показать матрицы" << endl;
        cout << "6. Сложить матрицы" << endl;
        cout << "7. Показать результат сложения" << endl;
        cout << "8. Очистить результат" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Ошибка ввода! Введите число." << endl;
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: {
                cin >> matrix1;
                cout << "Первая матрица установлена:" << endl;
                showMatrixInfo(matrix1, "Первая");
                break;
            }
            case 2: {
                cin >> matrix2;
                cout << "Вторая матрица установлена:" << endl;
                showMatrixInfo(matrix2, "Вторая");
                break;
            }
            case 3: {
                matrix1.clear();
                cout << "Первая матрица очищена" << endl;
                break;
            }
            case 4: {
                matrix2.clear();
                cout << "Вторая матрица очищена" << endl;
                break;
            }
            case 5: {
                showMatrixInfo(matrix1, "Первая");
                showMatrixInfo(matrix2, "Вторая");
                break;
            }
            case 6: {
                if (matrix1.getRows() == 0 || matrix1.getCols() == 0 ||
                    matrix2.getRows() == 0 || matrix2.getCols() == 0) {
                    cout << "Ошибка: одна или обе матрицы пусты!" << endl;
                    break;
                }
                try {
                    result = matrix1 + matrix2;
                    cout << "Сложение выполнено успешно!" << endl;
                    cout << "Размер результата: " << result.getRows() << "x" << result.getCols() << endl;
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what() << endl;
                }
                break;
            }
            case 7: {
                if (result.getRows() > 0 && result.getCols() > 0) {
                    cout << "Результат (" << result.getRows() << "x" << result.getCols() << "):" << endl;
                    cout << result;
                } else {
                    cout << "Результат еще не вычислен или пуст" << endl;
                }
                break;
            }
            case 8: {
                result.clear();
                cout << "Результат очищен" << endl;
                break;
            }
            case 0: {
                cout << "Выход из программы..." << endl;
                break;
            }
            default: {
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
            }
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.get();
        }

    } while (choice != 0);

    return 0;
}