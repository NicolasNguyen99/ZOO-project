//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_LOCATION_H
#define PROJEKT_LOCATION_H
#include <vector>
#include <array>
#include "Tile.h"

enum class locationType{Forest, Mountain, Swamp, Desert};
struct availableMovement{
    bool N = false;
    bool E = false;
    bool S = false;
    bool W = false;
};
enum class sizeOfLocation{Small=3,Medium=4,Large=5};
struct positionCoor{
    int x;
    int y;
};
struct sizeOfMovement{
    int x;
    int y;
};
typedef  std::vector<std::vector<Tile*>> matrixOfTiles;

class Location {
//    sizeOfLocation m_sizeOfLocation;
    static positionCoor m_currentCoorTile;
    Tile* m_currentTile;

protected:
    sizeOfLocation m_sizeOfLocation;
    locationType m_type;
    matrixOfTiles m_tiles;
    Location();

public:
    virtual void printLocation(int rowNum) = 0;
    static Location* getLocation(locationType type);
    void printTileMap();
    void renderLocation();
    void moveCurrentCoorTile(sizeOfMovement sizePosition);
    //void setCurrentCoorTile(positionCoor newPosition);
    void setCurrentTile();
    availableMovement checkMovement(positionCoor coor, int range);
    positionCoor getTilepositionCoor();
    void setStartingTile();
    sizeOfLocation getSize();
    locationType getType();
    void setSizeOfLocation(sizeOfLocation size);
};


#endif //PROJEKT_LOCATION_H
