#include "SmartArray.h"
#include <iostream>

int main() {
    std::setlocale(LC_ALL, "Russian");

    int n;
    int m;
    std::cout << "Введите начальный размер первого массива: ";
    std::cin >> n;
    std::cout << "Введите начальный размер второго массива: ";
    std::cin >> m;

    SmartArray arr1(n);
    SmartArray arr2(m);

    bool running = true;
    while (running) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Заполнить массивы вручную\n";
        std::cout << "2. Заполнить массивы случайными числами\n";
        std::cout << "3. Показать массивы\n";
        std::cout << "4. Найти пересечение массивов\n";
        std::cout << "5. Найти объединение массивов\n";
        std::cout << "6. Изменить размер массивов\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Заполнение первого массива:\n";
                arr1.fillManual();
                std::cout << "Заполнение второго массива:\n";
                arr2.fillManual();
                break;
            }
            case 2: {
                arr1.fillRandom();
                arr2.fillRandom();
                std::cout << "Массивы заполнены случайными числами.\n";
                break;
            }
            case 3: {
                std::cout << "Первый массив: ";
                arr1.print();
                std::cout << "Второй массив: ";
                arr2.print();
                break;
            }
            case 4: {
                SmartArray inter = SmartArray::intersection(arr1, arr2);
                std::cout << "Пересечение: ";
                inter.print();
                break;
            }
            case 5: {
                SmartArray uni = SmartArray::unionArrays(arr1, arr2);
                std::cout << "Объединение: ";
                uni.print();
                break;
            }
            case 6: {
                int newN;
                int newM;
                std::cout << "Введите новый размер первого массива: ";
                std::cin >> newN;
                std::cout << "Введите новый размер второго массива: ";
                std::cin >> newM;
                arr1.resize(newN);
                arr2.resize(newM);
                std::cout << "Размеры массивов изменены.\n";
                break;
            }
            case 0:
                running = false;
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }

    std::cout << "Программа завершена.\n";
    return 0;
}