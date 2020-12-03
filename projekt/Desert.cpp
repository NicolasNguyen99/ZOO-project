//
// Created by Kristina Nazarjanová on 03/12/2020.
//

#include "Desert.h"

Desert::Desert():Location(){}

void Desert::printLocation(int rowNum){
    std::array<std::string,5> rowPattern;
    rowPattern.at(0) ="          ,,       ";
    rowPattern.at(1) ="         || |   ,  ";
    rowPattern.at(2) ="         || '--' | ";
    rowPattern.at(3) ="   \\/    || .----' ";
    rowPattern.at(4) =". _||___.|  |_____ ";
    std::cout << rowPattern.at(rowNum);
}