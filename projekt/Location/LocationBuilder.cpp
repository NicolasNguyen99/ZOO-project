//
// Created by Nicolas Nguyen on 06/12/2020.
//

#include "LocationBuilder.h"

Location* LocationBuilder::getLocation(){
    return m_location;
}

void LocationBuilder::setTiles(){
    m_location->setTiles(m_tiles);
}
