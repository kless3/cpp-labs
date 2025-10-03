#include <utility>

#include "../include/Employee.h"

Employee::Employee() : employeeNumber(0) {}

Employee::Employee(std::string first, std::string middle, std::string last, int number)
        : firstName(std::move(first)), middleName(std::move(middle)), lastName(std::move(last)), employeeNumber(number) {}