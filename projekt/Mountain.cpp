//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Mountain.h"

Mountain::Mountain(std::string type):Location(type){}

void Mountain::printLocation(int rowNum){
    std::array<std::string,5> rowPattern;
    rowPattern.at(0) ="     /\\            ";
    rowPattern.at(1) ="    /**\\           ";
    rowPattern.at(2) ="   /****\\  /\\      ";
    rowPattern.at(3) ="  /  /\\  \\/  \\/\\   ";
    rowPattern.at(4) ="_/__/__\\_/___/__\\  ";
    std::cout << rowPattern.at(rowNum);
}