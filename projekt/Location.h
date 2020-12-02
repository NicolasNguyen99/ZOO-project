//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_LOCATION_H
#define PROJEKT_LOCATION_H
#include <vector>
#include <array>
#include "Tile.h"

struct positionCoor{
    int x;
    int y;
};
typedef  std::vector<std::vector<Tile*>> matrixOfTiles;

class Location {
//    static positionCoor m_currentCoor;
//    static Tile* currentTile;
protected:
    std::string m_locationType;
    matrixOfTiles m_tiles;
//    positionCoor m_currentCoor;
//    Tile* currentTile;

public:
    Location();
    virtual void printLocation(int rowNum) = 0;
    void printTileMap(positionCoor currentCoor);
    void renderLocation();
    matrixOfTiles getTiles();
};


#endif //PROJEKT_LOCATION_H
