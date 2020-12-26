//
// Created by Nicolas Nguyen on 07/12/2020.
//

#ifndef PROJEKT_SWAMPLOCATIONBUILDER_H
#define PROJEKT_SWAMPLOCATIONBUILDER_H
#include "LocationBuilder.h"

class SwampLocationBuilder:public LocationBuilder{

public:
    SwampLocationBuilder(){};
    void createLocation();
    void createTiles();
    void spawnEnemies();
    void spawnChests();
};


#endif //PROJEKT_SWAMPLOCATIONBUILDER_H
