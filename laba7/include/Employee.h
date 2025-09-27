#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
private:
    std::string firstName;
    std::string middleName;
    std::string lastName;
    int employeeNumber;

public:
    Employee();
    Employee(std::string  first, std::string  middle,
             std::string  last, int number);

    friend std::ostream& operator<<(std::ostream& os, const Employee& emp) {
        os << emp.firstName << " " << emp.middleName << " " << emp.lastName << " " << emp.employeeNumber;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Employee& emp) {
        is >> emp.firstName >> emp.middleName >> emp.lastName >> emp.employeeNumber;
        return is;
    }
};

#endif