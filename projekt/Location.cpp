//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Location.h"

Location::Location(){
    m_locationType = "Forest";
}

void Location::printLocation(int rowNum){}

void Location::printTileMap(positionCoor currentCoor){
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            Tile* tile = m_tiles.at(x).at(y);
            if(currentCoor.x != x or currentCoor.y != y){
                tile->printTile(false);
            } else {
                tile->printTile(true);
            }
        }
        std::cout << std::endl;
    }
};

void Location::renderLocation(){
    std::vector<Tile*> row1;
    std::vector<Tile*> row2;
    std::vector<Tile*> row3;

    row1.push_back(new Tile());row1.push_back(new Tile());row1.push_back(new Tile());
    row2.push_back(new Tile());row2.push_back(new Tile());row2.push_back(new Tile());
    row3.push_back(new Tile());row3.push_back(new Tile());row3.push_back(new Tile());

    m_tiles.push_back(row1);
    m_tiles.push_back(row2);
    m_tiles.push_back(row3);
}

matrixOfTiles  Location::getTiles(){
    return m_tiles;
};