//
// Created by Nicolas Nguyen on 06/12/2020.
//

#ifndef PROJEKT_LOCATIONBUILDER_H
#define PROJEKT_LOCATIONBUILDER_H
#include "Location.h"

class LocationBuilder {
protected:
    Location* m_location;
    matrixOfTiles m_tiles;

public:
    LocationBuilder(){};
    virtual void createLocation() = 0;
    virtual void createTiles() = 0;
    virtual void spawnEnemies() = 0;
    virtual void spawnChests() = 0;
    Location* getLocation();
    void setTiles();
};


#endif //PROJEKT_LOCATIONBUILDER_H
