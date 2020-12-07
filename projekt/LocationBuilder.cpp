//
// Created by Nicolas Nguyen on 06/12/2020.
//

#include "LocationBuilder.h"

void LocationBuilder::createLocation(){}

Location* LocationBuilder::getLocation(){
    return m_location;
}

void LocationBuilder::createTiles(){
    matrixOfTiles tiles;
    std::vector<Tile*> row1;
    std::vector<Tile*> row2;
    std::vector<Tile*> row3;

    row1.push_back(new Tile());row1.push_back(new Tile());row1.push_back(new Tile());
    row2.push_back(new Tile());row2.push_back(new Tile());row2.push_back(new Tile());
    row3.push_back(new Tile());row3.push_back(new Tile());row3.push_back(new Tile());

    tiles.push_back(row1);
    tiles.push_back(row2);
    tiles.push_back(row3);
    m_location->setTiles(tiles);
}
