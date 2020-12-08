//
// Created by Nicolas Nguyen on 06/12/2020.
//

#ifndef PROJEKT_MOUNTAINLOCATIONBUILDER_H
#define PROJEKT_MOUNTAINLOCATIONBUILDER_H
#include "LocationBuilder.h"

class MountainLocationBuilder:public LocationBuilder{

public:
    MountainLocationBuilder(){};
    void createLocation();
    void createTiles();
    void spawnEnemies();
    void spawnChests();
};


#endif //PROJEKT_MOUNTAINLOCATIONBUILDER_H
