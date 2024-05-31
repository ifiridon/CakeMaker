#include "CakeMaker.h"

#include <chrono>
#include <thread>

CakeMaker::CakeMaker() = default;

Cake CakeMaker::takeCommand(const RecipeCake& recipe) const {
    //std::this_thread::sleep_for(std::chrono::seconds(recipe.getTime()));
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return Cake(recipe.getName());
}
