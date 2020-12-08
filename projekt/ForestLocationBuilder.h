//
// Created by Nicolas Nguyen on 06/12/2020.
//

#ifndef PROJEKT_FORESTLOCATIONBUILDER_H
#define PROJEKT_FORESTLOCATIONBUILDER_H
#include "LocationBuilder.h"

class ForestLocationBuilder:public LocationBuilder{

public:
    ForestLocationBuilder(){};
    void createLocation();
    void createTiles();
    void spawnEnemies();
    void spawnChests();
};


#endif //PROJEKT_FORESTLOCATIONBUILDER_H
