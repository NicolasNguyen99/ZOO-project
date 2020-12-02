//
// Created by Nicolas Nguyen on 23/11/2020.
//

#ifndef PROJEKT_FORREST_H
#define PROJEKT_FORREST_H
#include "Tile.h"

class Forrest:public Tile{
public:
    Forrest(tileType type, bool isLocked);
    Forrest(tileType type);
    void printPattern(int rowNum);
};


#endif //PROJEKT_FORREST_H
