#pragma once
#include <string>

class Car {
private:
    std::string make_;
    std::string model_;
    int year_ = 0;
    int mileage_ = 0;

public:
    Car(const std::string& make, const std::string& model, int year);
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    int getMileage() const;
    int getAge(int currentYear) const;
    bool renameModel(const std::string& newModel);
    bool drive(int distance);
};
