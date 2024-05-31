#include "CommandPanel.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

CommandPanel::CommandPanel(const std::vector<RecipeCake>& menu) : menu(menu), commandTaker(CommandTaker(menu)) {
    if(menu.empty())
        throw std::invalid_argument("Lista de produse disponibile nu poate fi goala!");
}

void CommandPanel::showProducts() const {
    std::cout << "Lista produse disponibile:\n";
    int pos = 1;

    std::for_each(
            menu.begin(),
            menu.end(),
            [&pos] (auto rc) {std::cout << std::left << std::setw(7) <<std::to_string(pos++) + "." << rc << "\n";}
            );
}

void CommandPanel::selectProduct(const std::string &name) {
    try {
        commandTaker.takeCommand(name);
        std::cout << "Tortul " << name << " este pregatit!";
    } catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
}

void CommandPanel::selectProduct(const std::string &name, int numberOfProducts) {
    try {
        commandTaker.takeCommand(name, numberOfProducts);
        std::cout << "Cele " << numberOfProducts << " torturi " << name << " sunt pregatite!";
    } catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
}

void CommandPanel::showProductsInCarousel() {
    std::cout << "Lista torturi existente in depozitul circular:\n";
    int pos = 1;
    const std::vector<Cake>& cakeList = commandTaker.getCakesFromCarousel();

    std::for_each(
            cakeList.begin(),
            cakeList.end(),
            [&pos] (auto c) {std::cout << std::left << std::setw(7) << std::to_string(pos++) + "." << c << "\n";}
            );
}
