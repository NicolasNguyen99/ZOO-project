//
// Created by Nicolas Nguyen on 07/12/2020.
//

#ifndef PROJEKT_DESERTLOCATIONBUILDER_H
#define PROJEKT_DESERTLOCATIONBUILDER_H
#include "LocationBuilder.h"

class DesertLocationBuilder:public LocationBuilder{

public:
    DesertLocationBuilder(){};
    void createLocation();
    void createTiles();
    void spawnEnemies();
    void spawnChests();
};


#endif //PROJEKT_DESERTLOCATIONBUILDER_H
