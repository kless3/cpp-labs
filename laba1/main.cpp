#include "SmartArray.h"
#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n, m;
    cout << "Введите начальный размер первого массива: ";
    cin >> n;
    cout << "Введите начальный размер второго массива: ";
    cin >> m;

    SmartArray arr1(n), arr2(m);

    bool running = true;
    while (running) {
        cout << "\nМеню:\n";
        cout << "1. Заполнить массивы вручную\n";
        cout << "2. Заполнить массивы случайными числами\n";
        cout << "3. Показать массивы\n";
        cout << "4. Найти пересечение массивов\n";
        cout << "5. Найти объединение массивов\n";
        cout << "6. Изменить размер массивов\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Заполнение первого массива:\n";
                arr1.fillManual();
                cout << "Заполнение второго массива:\n";
                arr2.fillManual();
                break;
            case 2:
                arr1.fillRandom();
                arr2.fillRandom();
                cout << "Массивы заполнены случайными числами.\n";
                break;
            case 3:
                cout << "Первый массив: ";
                arr1.print();
                cout << "Второй массив: ";
                arr2.print();
                break;
            case 4: {
                SmartArray inter = SmartArray::intersection(arr1, arr2);
                cout << "Пересечение: ";
                inter.print();
                break;
            }
            case 5: {
                SmartArray uni = SmartArray::unionArrays(arr1, arr2);
                cout << "Объединение: ";
                uni.print();
                break;
            }
            case 6: {
                int newN, newM;
                cout << "Введите новый размер первого массива: ";
                cin >> newN;
                cout << "Введите новый размер второго массива: ";
                cin >> newM;
                arr1.resize(newN);
                arr2.resize(newM);
                cout << "Размеры массивов изменены.\n";
                break;
            }
            case 0:
                running = false;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }

    cout << "Программа завершена.\n";
    return 0;
}
