//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_MAP_H
#define PROJEKT_MAP_H
#include "Location/LocationDirector.h"

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
    positionCoor getCurrentCoorLocation();
    void setStartingLocation();
    void setStartingTile();
    positionCoor getTilepositionCoor();
    Enemy* getEnemy();
    //prejmenovat promenne
    void moveHeroFnc(bool avaliableTileMovement, bool availableLocationMovement, int x, int y, int moveX, int moveY);
};


#endif //PROJEKT_MAP_H
