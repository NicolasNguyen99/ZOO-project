//
// Created by Nicolas Nguyen on 23/11/2020.
//

#ifndef PROJEKT_MOUNTAIN_H
#define PROJEKT_MOUNTAIN_H
#include "Tile.h"

class Mountain:public Tile{
public:
    Mountain(tileType type, bool isLocked);
    Mountain(tileType type);
    void printPattern(int rowNum);
};


#endif //PROJEKT_MOUNTAIN_H
