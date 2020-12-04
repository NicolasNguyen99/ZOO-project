//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Forest.h"

Forest::Forest(std::string type):Location(type){}

void Forest::printLocation(int rowNum){
    std::array<std::string,5> rowPattern;
    rowPattern.at(0) ="                   ";
    rowPattern.at(1) ="   /\\              ";
    rowPattern.at(2) ="  /**\\   /\\        ";
    rowPattern.at(3) =" /****\\ /**\\       ";
    rowPattern.at(4) ="___||____||_______ ";
    std::cout << rowPattern.at(rowNum);
}