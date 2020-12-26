//
// Created by Nicolas Nguyen on 08/12/2020.
//

#ifndef PROJEKT_CAVELOCATIONBUILDER_H
#define PROJEKT_CAVELOCATIONBUILDER_H
#include "LocationBuilder.h"

class CaveLocationBuilder:public LocationBuilder{

public:
    CaveLocationBuilder(){};
    void createLocation();
    void createTiles();
    void spawnEnemies();
    void spawnChests();
};


#endif //PROJEKT_CAVELOCATIONBUILDER_H
