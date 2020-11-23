//
// Created by Nicolas Nguyen on 23/11/2020.
//

#ifndef PROJEKT_SWAMP_H
#define PROJEKT_SWAMP_H
#include "Tile.h"

class Swamp:public Tile{
public:
    Swamp(tileType type, bool isLocked);
    void printPattern();
};


#endif //PROJEKT_SWAMP_H
