//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Hell.h"

Hell::Hell():Location(){}

void Hell::printLocation(int rowNum){
    std::array<std::string,5> rowPattern;
    rowPattern.at(0) ="   ,,      )       ";
    rowPattern.at(1) =" W ()     ) \\      ";
    rowPattern.at(2) =" |-><    / ) )     ";
    rowPattern.at(3) =" | )(    \\(_)/     ";
    rowPattern.at(4) ="__________________";
    std::cout << rowPattern.at(rowNum);
}