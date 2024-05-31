#include "Cake.h"

#include <iostream>

Cake::Cake(const std::string& name) {
    if (name.length() < 1)
        throw std::invalid_argument("Numele unui tort nu poate fi gol!");
    this->name = name;
}

Cake::Cake(const Cake& cake) {
    this->name = cake.name;
}

std::string Cake::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Cake& c) {
    std::cout << c.name;
    return os;
}
