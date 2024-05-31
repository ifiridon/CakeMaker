#ifndef CAKEMAKER_CAKEMAKER_H
#define CAKEMAKER_CAKEMAKER_H


#include "../Cake/Cake.h"
#include "../RecipeCake/RecipeCake.h"

class CakeMaker final {
public:
    CakeMaker();

    Cake takeCommand(const RecipeCake& recipe) const;

};


#endif //CAKEMAKER_CAKEMAKER_H
