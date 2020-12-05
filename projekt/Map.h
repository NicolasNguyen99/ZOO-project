//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_MAP_H
#define PROJEKT_MAP_H
#include "Location.h"

const int sizeOfMap = 3;
const int asciiArtRows = 5;
enum class movementDirection{N,E,S,W};
typedef  std::vector<std::vector<Location*>> matrixOfLocation;

class Map {
    matrixOfLocation m_locations;
    positionCoor m_currentCoorLocation;
    Location* m_currentLocation;


public:
    Map();
    void printLocationMap();
    void printTileMap();
    void printMovementOptions();
    availableMovement checkMovement(positionCoor coor, int range);
    void moveHero(movementDirection direction);
    void createMap();
    void renderMap();
    void renderLocation();
    positionCoor getCurrentCoorLocation();
    void setStartingLocation();
    void setStartingTile();
    positionCoor getTilepositionCoor();
};


#endif //PROJEKT_MAP_H
