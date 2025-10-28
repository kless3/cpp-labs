#ifndef CAT_H
#define CAT_H

#include "Object.h"
#include <string>
#include <string_view>

class Cat : public Object {
private:
    std::string name;
    std::string breed;
    int age;

public:
    Cat();
    Cat(std::string_view name, std::string_view breed, int age);
    Cat(const Cat& other);
    ~Cat() override;

    Cat& operator=(const Cat& other);

    void setName(std::string_view name);
    void setBreed(std::string_view breed);
    void setAge(int age);

    std::string getName() const;
    std::string getBreed() const;
    int getAge() const;

    void display() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
    std::string getType() const override;
};

#endif