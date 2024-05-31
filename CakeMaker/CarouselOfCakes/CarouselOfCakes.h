#ifndef CAKEMAKER_CAROUSELOFCAKES_H
#define CAKEMAKER_CAROUSELOFCAKES_H

#include <vector>
#include <string>

#include "../Cake/Cake.h"

class CarouselOfCakes final {
private:
    std::vector<Cake> storage;
    const unsigned int max_capacity = 10; // 12
    const unsigned int low_limit = 3;

public:
    CarouselOfCakes();

    bool addCake(const Cake& cake);

    Cake getCake(const std::string& name);

    const std::vector<Cake>& getCakeList() const;

    int getCurrentCapacity() const;

    int getMaxCapacity() const;

    int getLowLimit() const;

};


#endif //CAKEMAKER_CAROUSELOFCAKES_H
