//
// Created by Nicolas Nguyen on 06/12/2020.
//

#ifndef PROJEKT_LOCATIONBUILDER_H
#define PROJEKT_LOCATIONBUILDER_H
#include "Location.h"

class LocationBuilder {
protected:
    Location* m_location;

public:
    LocationBuilder(){};
    virtual void createLocation() = 0;
    virtual Location* getLocation();
    void createTiles();
};


#endif //PROJEKT_LOCATIONBUILDER_H
