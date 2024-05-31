#include "RecipeCake.h"

#include <iomanip>
#include <iostream>

RecipeCake::RecipeCake(const std::string& name, int time) {
    if (time <= 0)
        throw std::invalid_argument("Timpul de asteptare pentru un tort nu poate fi <= 0!");
    if (name.length() < 1)
        throw std::invalid_argument("Numele unui tort nu poate fi gol!");

    this->name = name;
    this->time = time;
}

const std::string& RecipeCake::getName() const {
    return name;
}

int RecipeCake::getTime() const {
    return time;
}

bool RecipeCake::operator==(const RecipeCake& other) const {
    return (name == other.name) && (time == other.time);
}

std::ostream& operator<<(std::ostream& os, const RecipeCake& rc) {
    std::cout << "Nume: " << std::setfill('.')<< std::setw(60) << rc.name + ' ' << " - ";
    std::cout << "Timp de asteptare: " << std::setfill(' ') << std::right << std::setw(6) << rc.time << " minut";
    if (rc.time != 1)
        std::cout << 'e';
    return os;
}
