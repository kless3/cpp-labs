#ifndef ROSE_H
#define ROSE_H

#include "Object.h"
#include <string>
#include <string_view>

class Rose : public Object {
private:
    std::string color;
    std::string variety;
    int bloomLevel; // 1-10 уровень цветения
    bool hasThorns;

public:
    Rose();
    Rose(std::string_view color, std::string_view variety, int bloomLevel, bool hasThorns);
    Rose(const Rose& other);
    ~Rose() override;

    Rose& operator=(const Rose& other);

    void setColor(std::string_view color);
    void setVariety(std::string_view variety);
    void setBloomLevel(int bloomLevel);
    void setHasThorns(bool hasThorns);

    std::string getColor() const;
    std::string getVariety() const;
    int getBloomLevel() const;
    bool getHasThorns() const;

    void display() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
    std::string getType() const override;
};

#endif