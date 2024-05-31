#include "Menu.h"

#include <iostream>

Menu::Menu(CommandPanel &commandPanel) : commandPanel(commandPanel) {}

void Menu::printMenu(){
    std::cout << "\n"
              << "0. Iesire\n"
              << "1. Afisare meniu produse\n"
              << "2. Afisare produse depozit circular\n"
              << "3. Selectare produs\n"
              << "4. Selectare produse multiple\n"
              << "Introduceti optiunea dorita >";
}

std::string Menu::trim(const std::string& s) {
    if (s.empty())
        return s;

    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }

    auto end = s.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    std::string result = std::string(start, end + 1);

    return result;
}

int Menu::getNumber() {
    std::string line;
    std::getline(std::cin, line);

    line = trim(line);

    if (line.empty())
        return -1;

    int i, res = 0;

    for (i = 0; i < line.size(); i++) {
        if (!std::isdigit(line[i]))
            return -1;
        res = res * 10 + (line[i] - '0');
    }

    return res;
}

int Menu::getOption() {
    std::string line;
    std::getline(std::cin, line);

    line = trim(line);

    if (line.size() != 1)
        return -1;

    if (line[0] >= '0' && line[0] <= '4')
        return (int)(line[0] - '0');

    return -1;
}

void Menu::start() {

    std::cout << "\nBine ati venit!\n";

    bool done = false;
    int option;
    std::string line;

    while (!done) {
        printMenu();
        option = getOption();

        std::cout << '\n';
        switch (option) {
            case 0:
                done = true;
                break;
            case 1:
                commandPanel.showProducts();
                break;
            case 2:
                commandPanel.showProductsInCarousel();
                break;
            case 3:
                std::cout << "Introduceti numele tortului >";
                std::getline(std::cin, line);
                commandPanel.selectProduct(trim(line));
                break;
            case 4:
                std::cout << "Introduceti numele tortului >";
                std::getline(std::cin, line);
                std::cout << "Introduceti numarul de produse dorite >";
                commandPanel.selectProduct(trim(line), getNumber());
                break;
            default:
                std::cout << "Optiune gresita!";
        }

        std::cout << "\nLa revedere!\n";
    }
}
