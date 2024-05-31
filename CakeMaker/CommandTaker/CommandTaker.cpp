#include "CommandTaker.h"

#include <random>
#include <stdexcept>

CommandTaker::CommandTaker(const std::vector<RecipeCake>& recipes) : recipes(recipes) {
    if (recipes.empty())
        throw std::invalid_argument("Lista de produse disponibile nu poate fi goala!");

    refillCarousel();
}

Cake CommandTaker::takeCommand(const RecipeCake& recipe) {
    return takeCommand(recipe.getName());
}

std::vector<Cake> CommandTaker::takeCommand(const RecipeCake& recipe, int nrOfCakes) {
    return takeCommand(recipe.getName(), nrOfCakes);
}

Cake CommandTaker::takeCommand(const std::string& nameOfCake) {
    try {
        Cake c = carousel.getCake(nameOfCake);
        if (checkCarouselOfCakes())  // check if the number of carousel cakes reached the low limit
            refillCarousel();
        return c;
    } catch (std::invalid_argument& e) {
        auto it = recipes.begin();
        while (it != recipes.end()) {
            if (it->getName() == nameOfCake)
                return cakeMaker.takeCommand(*it);
            ++it;
        }
        throw std::invalid_argument("Nu exista nicio reteta de tort cu acest nume!");
    }
}

std::vector<Cake> CommandTaker::takeCommand(const std::string& nameOfCake, int nrOfCakes) {
    if (nrOfCakes < 2)
        throw std::invalid_argument("Numarul de torturi trebuie sa fie > 1");

    std::vector<Cake> cakes;
    bool ok = false;

    auto it = recipes.begin();
    while (it != recipes.end()) {
        if (it->getName() == nameOfCake) {
            ok = true;
            break;
        }
        ++it;
    }

    if (ok) {
        while(nrOfCakes--)
            cakes.emplace_back(cakeMaker.takeCommand(*it));
        return cakes;
    }

    throw std::invalid_argument("Nu exista nicio reteta de tort cu acest nume!");
}

const std::vector<Cake>& CommandTaker::getCakesFromCarousel() const {
    return carousel.getCakeList();
}

bool CommandTaker::checkCarouselOfCakes() const {
    if (carousel.getCurrentCapacity() > carousel.getLowLimit())
        return false;
    return true;
}

bool CommandTaker::refillCarousel() {
    if (carousel.getCurrentCapacity() > carousel.getLowLimit())
        return false;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, recipes.size() - 1);

    while(carousel.getCurrentCapacity() < carousel.getMaxCapacity())
        carousel.addCake(Cake(recipes.at(distribution(generator)).getName()));

    return true;
}
