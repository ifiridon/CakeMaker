#ifndef CAKEMAKER_COMMANDPANEL_H
#define CAKEMAKER_COMMANDPANEL_H


#include <vector>

#include "../CommandTaker/CommandTaker.h"
#include "../RecipeCake/RecipeCake.h"

class CommandPanel final {
private:
    const std::vector<RecipeCake>& menu;
    CommandTaker commandTaker;

public:
    explicit CommandPanel(const std::vector<RecipeCake>& menu);

    void showProducts() const;

    void selectProduct(const std::string& name);

    void selectProduct(const std::string& name, int numberOfProducts);

    void showProductsInCarousel();

};


#endif //CAKEMAKER_COMMANDPANEL_H
