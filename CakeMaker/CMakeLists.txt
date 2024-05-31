cmake_minimum_required(VERSION 3.20)
project(CakeMaker)

set(CMAKE_CXX_STANDARD 14)

add_executable(CakeMaker main.cpp Cake/Cake.cpp Cake/Cake.h RecipeCake/RecipeCake.cpp RecipeCake/RecipeCake.h CakeMaker/CakeMaker.cpp CakeMaker/CakeMaker.h CarouselOfCakes/CarouselOfCakes.cpp CarouselOfCakes/CarouselOfCakes.h CommandTaker/CommandTaker.cpp CommandTaker/CommandTaker.h CommandPanel/CommandPanel.cpp CommandPanel/CommandPanel.h Menu/Menu.cpp Menu/Menu.h)
