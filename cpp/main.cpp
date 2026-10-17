#include "Car.hpp"
#include <iostream>

int main() {
    Car first("Toyota", "Corolla", 2020);
    Car second("Honda", "Civic", 2022);
    first.drive(120);
    first.renameModel("Corolla Touring");
    std::cout << first.getMake() << " " << first.getModel()
              << " | year=" << first.getYear()
              << " | age=" << first.getAge(2026)
              << " | mileage=" << first.getMileage() << '\n';
    std::cout << second.getMake() << " " << second.getModel()
              << " | mileage=" << second.getMileage() << '\n';
    // TODO: pokaz odrzucona operacje i niezmieniony stan obiektu.
}

