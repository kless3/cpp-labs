#include "../include/Menu.h"
#include "../include/Employee.h"
#include <iostream>
#include <fstream>

using namespace std;

void inputEmployeesToFile() {
    ofstream outFile("employees.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    cout << "Enter employee data (type 'exit' for first name to stop):" << endl;

    while (true) {
        string middleName, lastName;
        string firstName;
        int employeeNumber;

        cout << "First name: ";
        cin >> firstName;

        if (firstName == "exit") {
            break;
        }

        cout << "Middle name: ";
        cin >> middleName;

        cout << "Last name: ";
        cin >> lastName;

        cout << "Employee number: ";
        cin >> employeeNumber;

        Employee emp(firstName, middleName, lastName, employeeNumber);
        outFile << emp << endl;

        cout << "Employee added successfully!" << endl;
    }

    outFile.close();
    cout << "Data saved to file." << endl;
}

void readEmployeesFromFile() {
    ifstream inFile("employees.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }


    Employee emp;
    int count = 0;

    while (inFile >> emp) {
        ++count;
        cout << "Employee " << count << ": " << emp << endl;
    }

    inFile.close();

    if (count == 0) {
        cout << "No employees found in file." << endl;
    } else {
        cout << "Total employees: " << count << endl;
    }
}

void clearEmployeesFile() {
    ofstream outFile("employees.txt", ios::trunc);
    if (!outFile) {
        cout << "Error clearing file!" << endl;
        return;
    }
    outFile.close();
    cout << "File cleared successfully!" << endl;
}

void displayMainMenu() {
    cout << "1. Input employees to file" << endl;
    cout << "2. Read employees from file" << endl;
    cout << "3. Clear employees file" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

