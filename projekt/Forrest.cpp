//
// Created by Nicolas Nguyen on 23/11/2020.
//

#include "Forrest.h"

Forrest::Forrest(tileType type, bool isLocked):Tile(type, isLocked){}
Forrest::Forrest(tileType type):Tile(type, false){};

void Forrest::printPattern(int rowNum){
    std::array<std::string,5> rowPattern;
    rowPattern.at(0) ="                   ";
    rowPattern.at(1) ="   /\\              ";
    rowPattern.at(2) ="  /**\\   /\\        ";
    rowPattern.at(3) =" /****\\ /**\\       ";
    rowPattern.at(4) ="___||____||_______ ";
    std::cout << rowPattern.at(rowNum);
}