#include "SmartArray.h"
#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n, m;
    cout << "������� ��������� ������ ������� �������: ";
    cin >> n;
    cout << "������� ��������� ������ ������� �������: ";
    cin >> m;

    SmartArray arr1(n), arr2(m);

    bool running = true;
    while (running) {
        cout << "\n����:\n";
        cout << "1. ��������� ������� �������\n";
        cout << "2. ��������� ������� ���������� �������\n";
        cout << "3. �������� �������\n";
        cout << "4. ����� ����������� ��������\n";
        cout << "5. ����� ����������� ��������\n";
        cout << "6. �������� ������ ��������\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "���������� ������� �������:\n";
                arr1.fillManual();
                cout << "���������� ������� �������:\n";
                arr2.fillManual();
                break;
            case 2:
                arr1.fillRandom();
                arr2.fillRandom();
                cout << "������� ��������� ���������� �������.\n";
                break;
            case 3:
                cout << "������ ������: ";
                arr1.print();
                cout << "������ ������: ";
                arr2.print();
                break;
            case 4: {
                SmartArray inter = SmartArray::intersection(arr1, arr2);
                cout << "�����������: ";
                inter.print();
                break;
            }
            case 5: {
                SmartArray uni = SmartArray::unionArrays(arr1, arr2);
                cout << "�����������: ";
                uni.print();
                break;
            }
            case 6: {
                int newN, newM;
                cout << "������� ����� ������ ������� �������: ";
                cin >> newN;
                cout << "������� ����� ������ ������� �������: ";
                cin >> newM;
                arr1.resize(newN);
                arr2.resize(newM);
                cout << "������� �������� ��������.\n";
                break;
            }
            case 0:
                running = false;
                break;
            default:
                cout << "�������� �����! ���������� �����.\n";
        }
    }

    cout << "��������� ���������.\n";
    return 0;
}
