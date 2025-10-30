#ifndef CAR_H
#define CAR_H

#include "Object.h"
#include <string>
#include <string_view>

class Car : public Object {
private:
    std::string brand;
    std::string model;
    int year;
    double price;

public:
    Car();
    Car(std::string_view brand, std::string_view model, int year, double price);
    Car(const Car& other);
    ~Car() override;

    Car& operator=(const Car& other);

    void display() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
    std::string getType() const override;
};

#endif