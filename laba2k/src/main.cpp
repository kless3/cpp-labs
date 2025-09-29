#include "../include/Matrix.h"
#include "../include/Functions.h"

const int EXIT_OPTION = 3;

using namespace std;

int main() {
    int choice;
    Matrix matrix1;
    Matrix matrix2;
    Matrix result;

    do {
        cout << "1. Enter matrices" << endl;
        cout << "2. Show addition result" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose action: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Input error! Please enter a number." << endl;
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                enterMatrices(matrix1, matrix2);
                addMatrices(matrix1, matrix2, result);
                break;
            case 2:
                showResult(result);
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        if (choice != EXIT_OPTION && choice != 1) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }

    } while (choice != EXIT_OPTION);

    return 0;
}