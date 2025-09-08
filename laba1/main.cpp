#include "SmartArray.h"
#include <iostream>

int main() {
    std::setlocale(LC_ALL, "Russian");

    int n;
    int m;
    std::cout << "������� ��������� ������ ������� �������: ";
    std::cin >> n;
    std::cout << "������� ��������� ������ ������� �������: ";
    std::cin >> m;

    SmartArray arr1(n);
    SmartArray arr2(m);

    bool running = true;
    while (running) {
        std::cout << "\n����:\n";
        std::cout << "1. ��������� ������� �������\n";
        std::cout << "2. ��������� ������� ���������� �������\n";
        std::cout << "3. �������� �������\n";
        std::cout << "4. ����� ����������� ��������\n";
        std::cout << "5. ����� ����������� ��������\n";
        std::cout << "6. �������� ������ ��������\n";
        std::cout << "0. �����\n";
        std::cout << "�������� ��������: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "���������� ������� �������:\n";
                arr1.fillManual();
                std::cout << "���������� ������� �������:\n";
                arr2.fillManual();
                break;
            }
            case 2: {
                arr1.fillRandom();
                arr2.fillRandom();
                std::cout << "������� ��������� ���������� �������.\n";
                break;
            }
            case 3: {
                std::cout << "������ ������: ";
                arr1.print();
                std::cout << "������ ������: ";
                arr2.print();
                break;
            }
            case 4: {
                SmartArray inter = SmartArray::intersection(arr1, arr2);
                std::cout << "�����������: ";
                inter.print();
                break;
            }
            case 5: {
                SmartArray uni = SmartArray::unionArrays(arr1, arr2);
                std::cout << "�����������: ";
                uni.print();
                break;
            }
            case 6: {
                int newN;
                int newM;
                std::cout << "������� ����� ������ ������� �������: ";
                std::cin >> newN;
                std::cout << "������� ����� ������ ������� �������: ";
                std::cin >> newM;
                arr1.resize(newN);
                arr2.resize(newM);
                std::cout << "������� �������� ��������.\n";
                break;
            }
            case 0:
                running = false;
                break;
            default:
                std::cout << "�������� �����! ���������� �����.\n";
        }
    }

    std::cout << "��������� ���������.\n";
    return 0;
}