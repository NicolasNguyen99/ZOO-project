//
// Created by Kristina Nazarjanová on 03/12/2020.
//

#include "Swamp.h"

Swamp::Swamp(std::string type):Location(type){}

void Swamp::printLocation(int rowNum){
    std::array<std::string, 5> rowPattern;
    rowPattern.at(0) ="                    ";
    rowPattern.at(1) ="   /|\\          /\\   ";
    rowPattern.at(2) ="  / | \\        /| \\  ";
    rowPattern.at(3) =" /  |  \\  \\/  / /  \\  ";
    rowPattern.at(4) ="~~~||~~~~~||~~~~||~~ ";
    std::cout << rowPattern.at(rowNum);
}