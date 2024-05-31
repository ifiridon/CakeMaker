#include "CommandPanel/CommandPanel.h"
#include "Menu/Menu.h"

int main() {
    std::vector<RecipeCake> recipes;
    recipes.emplace_back("a", 1);
    recipes.emplace_back("b", 2);
    recipes.emplace_back("c", 10);
    recipes.emplace_back("d", 5);
    recipes.emplace_back("e", 1);
    recipes.emplace_back("f", 3);

    CommandPanel commandPanel(recipes);

    Menu m(commandPanel);
    m.start();

    return 0;
}
