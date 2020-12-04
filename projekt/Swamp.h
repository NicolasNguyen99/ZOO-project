//
// Created by Kristina Nazarjanová on 03/12/2020.
//

#ifndef PROJEKT_SWAMP_H
#define PROJEKT_SWAMP_H
#include "Location.h"


class Swamp: public Location {
public:
    Swamp(std::string type);
    void printLocation(int rowNum);
    };



#endif //PROJEKT_SWAMP_H
