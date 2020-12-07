//
// Created by Nicolas Nguyen on 06/12/2020.
//

#ifndef PROJEKT_LOCATIONDIRECTOR_H
#define PROJEKT_LOCATIONDIRECTOR_H
#include "ForestLocationBuilder.h"
#include "MountainLocationBuilder.h"

class LocationDirector {
    LocationBuilder* m_builder;

public:
    LocationDirector(LocationBuilder* builder);
    void setBuilder(LocationBuilder* builder);
    Location* createLocation();
};


#endif //PROJEKT_LOCATIONDIRECTOR_H
