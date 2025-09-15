#include "../include/Matrix.h"
#include "../include/Functions.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    Matrix matrix1;
    Matrix matrix2;
    Matrix result;

    do {
        cout << "1. Enter/modify first matrix" << endl;
        cout << "2. Enter/modify second matrix" << endl;
        cout << "3. Clear first matrix" << endl;
        cout << "4. Clear second matrix" << endl;
        cout << "5. Show matrices" << endl;
        cout << "6. Add matrices" << endl;
        cout << "7. Show addition result" << endl;
        cout << "8. Clear result" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose action: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Input error! Please enter a number." << endl;
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: {
                cin >> matrix1;
                cout << "First matrix set:" << endl;
                showMatrixInfo(matrix1, "First");
                break;
            }
            case 2: {
                cin >> matrix2;
                cout << "Second matrix set:" << endl;
                showMatrixInfo(matrix2, "Second");
                break;
            }
            case 3: {
                matrix1.clear();
                cout << "First matrix cleared" << endl;
                break;
            }
            case 4: {
                matrix2.clear();
                cout << "Second matrix cleared" << endl;
                break;
            }
            case 5: {
                showMatrixInfo(matrix1, "First");
                showMatrixInfo(matrix2, "Second");
                break;
            }
            case 6: {
                if (matrix1.getRows() == 0 || matrix1.getCols() == 0 ||
                    matrix2.getRows() == 0 || matrix2.getCols() == 0) {
                    cout << "Error: one or both matrices are empty!" << endl;
                    break;
                }
                try {
                    result = matrix1 + matrix2;
                    cout << "Addition completed successfully!" << endl;
                    cout << "Result size: " << result.getRows() << "x" << result.getCols() << endl;
                } catch (const exception &e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 7: {
                if (result.getRows() > 0 && result.getCols() > 0) {
                    cout << "Result (" << result.getRows() << "x" << result.getCols() << "):" << endl;
                    cout << result;
                } else {
                    cout << "Result not yet calculated or empty" << endl;
                }
                break;
            }
            case 8: {
                result.clear();
                cout << "Result cleared" << endl;
                break;
            }
            case 0: {
                cout << "Exiting program..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }

        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }

    } while (choice != 0);

    return 0;
}