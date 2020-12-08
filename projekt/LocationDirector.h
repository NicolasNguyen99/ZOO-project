//
// Created by Nicolas Nguyen on 06/12/2020.
//

#ifndef PROJEKT_LOCATIONDIRECTOR_H
#define PROJEKT_LOCATIONDIRECTOR_H
#include "ForestLocationBuilder.h"
#include "MountainLocationBuilder.h"
#include "SwampLocationBuilder.h"
#include "DesertLocationBuilder.h"
#include "PlainLocationBuilder.h"
#include "CastleLocationBuilder.h"
#include "HellLocationBuilder.h"
#include "HeavenLocationBuilder.h"
#include "CaveLocationBuilder.h"

class LocationDirector {
    LocationBuilder* m_builder;

public:
    LocationDirector(LocationBuilder* builder);
    void setBuilder(LocationBuilder* builder);
    Location* createLocation();
};


#endif //PROJEKT_LOCATIONDIRECTOR_H
