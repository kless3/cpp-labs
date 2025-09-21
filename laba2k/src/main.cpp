#include "../include/Matrix.h"
#include "../include/Functions.h"

const int EXIT_OPTION = 0;

using namespace std;

int main() {
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
            case 1:
                enterFirstMatrix(matrix1);
                break;
            case 2:
                enterSecondMatrix(matrix2);
                break;
            case 3:
                clearFirstMatrix(matrix1);
                break;
            case 4:
                clearSecondMatrix(matrix2);
                break;
            case 5:
                showMatrices(matrix1, matrix2);
                break;
            case 6:
                addMatrices(matrix1, matrix2, result);
                break;
            case 7:
                showResult(result);
                break;
            case 8:
                clearResult(result);
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        if (choice != EXIT_OPTION) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }

    } while (choice != EXIT_OPTION);

    return 0;
}
