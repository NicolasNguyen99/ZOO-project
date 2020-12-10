//
// Created by Nicolas Nguyen on 08/12/2020.
//

#ifndef PROJEKT_CASTLELOCATIONBUILDER_H
#define PROJEKT_CASTLELOCATIONBUILDER_H
#include "LocationBuilder.h"

class CastleLocationBuilder:public LocationBuilder{

public:
    CastleLocationBuilder(){};
    void createLocation();
    void createTiles();
    void spawnEnemies();
    void spawnChests();
};


#endif //PROJEKT_CASTLELOCATIONBUILDER_H
