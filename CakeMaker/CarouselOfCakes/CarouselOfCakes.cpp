#include "CarouselOfCakes.h"

#include <algorithm>
#include <stdexcept>

CarouselOfCakes::CarouselOfCakes() = default;

bool CarouselOfCakes::addCake(const Cake& cake) {
    if (storage.size() >= max_capacity)
        return false;
    storage.emplace_back(cake);
    return true;
}

Cake CarouselOfCakes::getCake(const std::string& name) {
    auto it = storage.begin();
    while (it != storage.end()) {
        if (it->getName() == name) {
            Cake cake = *it;
            storage.erase(storage.begin() + std::distance(storage.begin(), it));
            return cake;
        }
        ++it;
    }

    throw std::invalid_argument("In depozitul circular nu exista tortul " + name + "!");
}

const std::vector<Cake>& CarouselOfCakes::getCakeList() const {
    return storage;
}

int CarouselOfCakes::getCurrentCapacity() const {
    return storage.size();
}

int CarouselOfCakes::getMaxCapacity() const {
    return max_capacity;
}

int CarouselOfCakes::getLowLimit() const {
    return low_limit;
}
