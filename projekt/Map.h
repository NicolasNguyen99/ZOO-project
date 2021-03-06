//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_MAP_H
#define PROJEKT_MAP_H
#include "Locations/LocationDirector.h"

enum class movementDirection{N=1,E=2,S=-1,W=-2};
typedef  std::vector<std::vector<Location*>> MatrixOfLocation;

class Map {
    MatrixOfLocation m_locations;
    positionCoor m_currentLocationCoor;
    Location* m_currentLocation;
    movementDirection m_previousMovement;
    void createMap();

public:
    Map();
    void printLocationMap();
    void printTileMap();
    void printMovementOptions();
    void moveHero(movementDirection direction);
    void setStartingLocation();
    void setStartingTile();
    positionCoor getTilePositionCoor();
    Enemy* getEnemy();
    void removeChest();
    objectsInTile getObjectsInTile();
    void killEnemy();
    void printEnemyStats();
    movementDirection getPreviousMovement();

    //prejmenovat promenne
    void moveHeroFnc(bool avaliableTileMovement, bool availableLocationMovement, int x, int y, int moveX, int moveY);
};


#endif //PROJEKT_MAP_H
