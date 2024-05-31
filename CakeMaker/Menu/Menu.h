#ifndef CAKEMAKER_MENU_H
#define CAKEMAKER_MENU_H


#include "../CommandPanel/CommandPanel.h"

class Menu final {
private:
    CommandPanel& commandPanel;

    static void printMenu();

    static std::string trim(const std::string& s);

    static int getNumber();

    static int getOption();

public:
    explicit Menu(CommandPanel& commandPanel);

    void start();

};


#endif //CAKEMAKER_MENU_H
