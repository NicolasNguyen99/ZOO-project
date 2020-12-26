//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_MAP_H
#define PROJEKT_MAP_H
#include "Locations/LocationDirector.h"

enum class movementDirection{N,E,S,W};
typedef  std::vector<std::vector<Location*>> MatrixOfLocation;

class Map {
    MatrixOfLocation m_locations;
    positionCoor m_currentLocationCoor;
    Location* m_currentLocation;
    void createMap();

public:
    Map();
    void printLocationMap();
    void printTileMap();
    void printMovementOptions();
    availableMovement checkMovement(positionCoor coor, int range);
    void moveHero(movementDirection direction);
    void setStartingLocation();
    void setStartingTile();
    positionCoor getTilePositionCoor();
    Enemy* getEnemy();
    void removeChest();
    objectsInTile getObjectsInTile();
    void killEnemy();
    //prejmenovat promenne
    void moveHeroFnc(bool avaliableTileMovement, bool availableLocationMovement, int x, int y, int moveX, int moveY);
};


#endif //PROJEKT_MAP_H
