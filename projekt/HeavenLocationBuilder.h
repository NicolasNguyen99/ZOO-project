//
// Created by Nicolas Nguyen on 08/12/2020.
//

#ifndef PROJEKT_HEAVENLOCATIONBUILDER_H
#define PROJEKT_HEAVENLOCATIONBUILDER_H
#include "LocationBuilder.h"

class HeavenLocationBuilder:public LocationBuilder{

public:
    HeavenLocationBuilder(){};
    void createLocation();
    void createTiles();
    void spawnEnemies();
    void spawnChests();
};


#endif //PROJEKT_HEAVENLOCATIONBUILDER_H
