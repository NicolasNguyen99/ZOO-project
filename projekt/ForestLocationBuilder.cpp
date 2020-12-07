//
// Created by Nicolas Nguyen on 06/12/2020.
//

#include "ForestLocationBuilder.h"

void ForestLocationBuilder::createLocation(){
    m_location = new Location("Forest of printers", 1);
    std::array<std::string,5> rowPattern;
    rowPattern.at(0) ="                   ";
    rowPattern.at(1) ="   /\\              ";
    rowPattern.at(2) ="  /**\\   /\\        ";
    rowPattern.at(3) =" /****\\ /**\\       ";
    rowPattern.at(4) ="___||____||_______ ";
    m_location->setPattern(rowPattern);
    m_location->setBonusOfLocation({-2*m_location->getLocationLevel(), -1*m_location->getLocationLevel(), 0});
    m_location->setType(locationType::Forest);
}