#ifndef CAKEMAKER_COMMANDTAKER_H
#define CAKEMAKER_COMMANDTAKER_H


#include <vector>

#include "../CakeMaker/CakeMaker.h"
#include "../CarouselOfCakes/CarouselOfCakes.h"
#include "../RecipeCake/RecipeCake.h"

class CommandTaker final {
private:
    const std::vector<RecipeCake>& recipes;
    const CakeMaker cakeMaker;
    CarouselOfCakes carousel;

public:
    explicit CommandTaker(const std::vector<RecipeCake>& recipes);

    Cake takeCommand(const RecipeCake& recipe);

    std::vector<Cake> takeCommand(const RecipeCake& recipe, int nrOfCakes);

    Cake takeCommand(const std::string& nameOfCake);

    std::vector<Cake> takeCommand(const std::string& nameOfCake, int nrOfCakes);

    const std::vector<Cake>& getCakesFromCarousel() const;

    bool checkCarouselOfCakes() const;

    bool refillCarousel();

};


#endif //CAKEMAKER_COMMANDTAKER_H
