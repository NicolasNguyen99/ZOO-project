//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_MAP_H
#define PROJEKT_MAP_H
#include "Forest.h"
#include "Mountain.h"

enum class movementDirection{N,E,S,W};
typedef  std::vector<std::vector<Location*>> matrixOfLocation;
enum class sizeOfMap{Small=3,Medium=4,Large=5};

class Map {
    matrixOfLocation m_locations;
//    positionCoor m_currentCoorLocation;
    Location* m_currentLocation;
    sizeOfMap m_size;
//    positionCoor m_currentCoorTile;
    Tile* m_currentTile;

public:
    Map();
    void renderSmallMap();
    void renderLocation();
    void printLocationMap();
    void printTileMap();
    void printMovementOptions();
    positionCoor m_currentCoorLocation;
    positionCoor m_currentCoorTile;
    void moveHero(movementDirection direction);
};


#endif //PROJEKT_MAP_H
