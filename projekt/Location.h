//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_LOCATION_H
#define PROJEKT_LOCATION_H
#include <vector>
#include <array>
#include "Tile.h"

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
    sizeOfLocation m_sizeOfLocation;
    static positionCoor m_currentCoorTile;
    Tile* m_currentTile;
    std::string m_type;

protected:
    std::string m_locationType;
    matrixOfTiles m_tiles;

public:
    Location(std::string type);
    virtual void printLocation(int rowNum) = 0;
    void printTileMap();
    void renderLocation();
    void moveCurrentCoorTile(sizeOfMovement sizePosition);
    //void setCurrentCoorTile(positionCoor newPosition);
    void setCurrentTile();
    availableMovement checkMovement(positionCoor coor, int range);
    positionCoor getTilepositionCoor();
    void setStartingTile();
    sizeOfLocation getSize();
    std::string getType();
};


#endif //PROJEKT_LOCATION_H
