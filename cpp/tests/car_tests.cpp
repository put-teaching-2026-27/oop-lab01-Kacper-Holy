#include "../Car.hpp"
#include <iostream>

int main() {
    int failed = 0;
    auto check = [&failed](bool condition, const char* name) {
        std::cout << (condition ? "PASS: " : "FAIL: ") << name << '\n';
        if (!condition) ++failed;
    };
    Car a("Toyota", "Corolla", 2020);
    Car b("Honda", "Civic", 2022);
    Car c("Ford", "Focus", 2021);
    check(a.getMake() == "Toyota", "constructor make");
    check(a.getModel() == "Corolla", "constructor model");
    check(a.getYear() == 2020, "constructor year");
    check(a.getMileage() == 0, "initial mileage");
    check(a.getAge(2026) == 6, "age normal");
    check(a.getAge(2020) == 0, "age zero");
    check(a.getAge(2019) == -1, "age invalid");
    check(a.drive(120), "drive positive");
    check(a.getMileage() == 120, "mileage after drive");
    check(a.drive(30), "drive again");
    check(a.getMileage() == 150, "mileage accumulates");
    check(!a.drive(0), "drive zero rejected");
    check(!a.drive(-50), "drive negative rejected");
    check(a.getMileage() == 150, "rejected drive preserves state");
    check(b.getMileage() == 0, "independent mileage");
    check(a.renameModel("Touring"), "rename accepted");
    check(a.getModel() == "Touring", "renamed model");
    check(!a.renameModel(""), "empty rejected");
    check(!a.renameModel(" \t\r\n"), "whitespace rejected");
    check(a.getModel() == "Touring", "rejected rename preserves state");
    check(b.getModel() == "Civic", "independent model");
    check(a.getMake() == "Toyota", "immutable make");
    check(a.getYear() == 2020, "immutable year");
    check(c.drive(1000000), "drive upper bound");
    check(!c.drive(1), "reject overflow of domain");
    check(c.getMileage() == 1000000, "upper bound preserves state");
    std::cout << "Failed: " << failed << "\n";
    return failed == 0 ? 0 : 1;
}
