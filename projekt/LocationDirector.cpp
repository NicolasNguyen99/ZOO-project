//
// Created by Nicolas Nguyen on 06/12/2020.
//

#include "LocationDirector.h"

LocationDirector::LocationDirector(LocationBuilder* builder){
    m_builder = builder;
}

void LocationDirector::setBuilder(LocationBuilder* builder){
    m_builder = builder;
}

Location* LocationDirector::createLocation(){
    m_builder->createLocation();
    m_builder->createTiles();
    return m_builder->getLocation();
}
