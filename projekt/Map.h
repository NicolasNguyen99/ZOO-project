//
// Created by Nicolas Nguyen on 23/11/2020.
//

#ifndef PROJEKT_MAP_H
#define PROJEKT_MAP_H
#include <vector>
#include "Swamp.h"
#include "Forrest.h"
#include "Mountain.h"

typedef std::vector<std::vector<Tile*>> matrixOfTiles;

enum class mapSize{Small=4,Medium=5,Large=6};

struct positionCoor{
    int x;
    int y;
};

class Map {
    matrixOfTiles m_tiles;
    positionCoor m_currentCoor;
    Tile* m_currentTile;
    mapSize m_size;
    void renderSmallMap();
    void renderMediumMap();
    void renderLargeMap();

public:
    Map(mapSize size);
    void createMap();
    positionCoor getCurrentCoor();
    matrixOfTiles getTiles();
    mapSize getSize();
    Tile* getCurrentTile();
    void setCurrentCoor(positionCoor currentCoor);
    void setCurrentTile(Tile* currentTile);
    void printMap();
};


#endif //PROJEKT_MAP_H
