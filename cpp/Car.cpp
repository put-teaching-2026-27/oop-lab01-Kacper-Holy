#include "Car.hpp"

// TODO: uzupelnij implementacje. Interfejs pozostaje bez zmian.
Car::Car(const std::string& make, const std::string& model, int year) {
    (void)make; (void)model; (void)year;
}
std::string Car::getMake() const { return ""; }
std::string Car::getModel() const { return ""; }
int Car::getYear() const { return 0; }
int Car::getMileage() const { return 0; }
int Car::getAge(int currentYear) const { (void)currentYear; return -1; }
bool Car::renameModel(const std::string& newModel) { (void)newModel; return false; }
bool Car::drive(int distance) { (void)distance; return false; }
