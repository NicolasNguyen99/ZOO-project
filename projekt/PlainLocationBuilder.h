//
// Created by Nicolas Nguyen on 08/12/2020.
//

#ifndef PROJEKT_PLAINLOCATIONBUILDER_H
#define PROJEKT_PLAINLOCATIONBUILDER_H
#include "LocationBuilder.h"

class PlainLocationBuilder:public LocationBuilder{

public:
    PlainLocationBuilder(){};
    void createLocation();
    void createTiles();
    void spawnEnemies();
    void spawnChests();
};


#endif //PROJEKT_PLAINLOCATIONBUILDER_H
