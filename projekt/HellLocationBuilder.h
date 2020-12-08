//
// Created by Nicolas Nguyen on 08/12/2020.
//

#ifndef PROJEKT_HELLLOCATIONBUILDER_H
#define PROJEKT_HELLLOCATIONBUILDER_H
#include "LocationBuilder.h"

class HellLocationBuilder:public LocationBuilder{

public:
    HellLocationBuilder(){};
    void createLocation();
    void createTiles();
    void spawnEnemies();
    void spawnChests();
};


#endif //PROJEKT_HELLLOCATIONBUILDER_H
