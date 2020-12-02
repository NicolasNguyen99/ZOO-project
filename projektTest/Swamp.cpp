//
// Created by Nicolas Nguyen on 23/11/2020.
//

#include "Swamp.h"

Swamp::Swamp(tileType type, bool isLocked):Tile(type, isLocked){}
Swamp::Swamp(tileType type):Tile(type){}

void Swamp::printPattern(int rowNum){
    std::array<std::string,5> rowPattern;
    rowPattern.at(0) ="     /\\            ";
    rowPattern.at(1) ="    /**\\           ";
    rowPattern.at(2) ="   /****\\  /\\      ";
    rowPattern.at(3) ="  /  /\\  \\/  \\/\\   ";
    rowPattern.at(4) ="_/__/__\\_/___/__\\  ";
    std::cout << rowPattern.at(rowNum);
}