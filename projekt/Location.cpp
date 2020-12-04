//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Location.h"

positionCoor Location::m_currentCoorTile;

Location::Location(std::string type){
    m_type = type;
    m_sizeOfLocation = sizeOfLocation::Small;
}

void Location::setStartingTile(){
    //staticka slozka spolecna pro vsechny lokace
    m_currentCoorTile = {int(m_sizeOfLocation)-1,0};
    setCurrentTile();
}

void Location::moveCurrentCoorTile(sizeOfMovement sizePosition){
    m_currentCoorTile.x = (m_currentCoorTile.x + sizePosition.x)%(int(m_sizeOfLocation));
    m_currentCoorTile.y = (m_currentCoorTile.y + sizePosition.y)%(int(m_sizeOfLocation));
}

//void Location::setCurrentCoorTile(positionCoor newPosition){
//    m_currentCoorTile = newPosition;
//}

void Location::setCurrentTile(){
    m_currentTile = m_tiles.at(m_currentCoorTile.x).at(m_currentCoorTile.y);
}

positionCoor Location::getTilepositionCoor(){
    return m_currentCoorTile;
}

sizeOfLocation Location::getSize(){
    return m_sizeOfLocation;
}

availableMovement Location::checkMovement(positionCoor coor, int range){
    availableMovement movement;
    if(coor.x-1 >= 0){
        movement.N = true;
    }
    if(coor.y+1 < range){
        movement.E = true;
    }
    if(coor.x+1 < range){
        movement.S = true;
    }
    if(coor.y-1 >= 0){
        movement.W = true;
    }
    return movement;
}

void Location::printTileMap(){
    for(int x = 0; x < int(m_sizeOfLocation); x++){
        for(int y = 0; y < int(m_sizeOfLocation); y++){
            Tile* tile = m_tiles.at(x).at(y);
            if(m_currentCoorTile.x != x or m_currentCoorTile.y != y){
                tile->printTile(false);
            } else {
                tile->printTile(true);
            }
        }
        std::cout << std::endl;
    }
}

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

void printLocation(){}

std::string Location::getType(){
    return m_type;
}