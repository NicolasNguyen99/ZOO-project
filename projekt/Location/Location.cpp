//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Location.h"

Location::Location(std::string name, int level){
    m_name = name;
    m_locationLevel = level;
}

positionCoor Location::m_currentCoorTile;

weaponBonusLocation Location::getBonusOfLocation(){
    return m_bonusOfLocation;
}

void Location::setBonusOfLocation(weaponBonusLocation bonus){
    m_bonusOfLocation = bonus;
}

void Location::setTiles(matrixOfTiles tiles){
    m_tiles = tiles;
}

void Location::setPattern(matrixOfAsciiArt rowPattern){
    m_pattern = rowPattern;
}

Enemy* Location::getEnemy(){
    return m_currentTile->getEnemy();
}

void Location::setStartingTile(){
    //staticka slozka spolecna pro vsechny lokace
    m_currentCoorTile = {int(m_tiles.size())-1,0};
    setCurrentTile();
}

void Location::moveCurrentCoorTile(sizeOfMovement sizePosition){
    m_currentCoorTile.x = (m_currentCoorTile.x + sizePosition.x)%(int(m_tiles.size()));
    m_currentCoorTile.y = (m_currentCoorTile.y + sizePosition.y)%(int(m_tiles.size()));
}

//void Location::setCurrentCoorTile(positionCoor newPosition){
//    m_currentCoorTile = newPosition;
//}

void Location::setCurrentTile(){
    m_currentTile = m_tiles.at(m_currentCoorTile.x).at(m_currentCoorTile.y);
}

void Location::printLocation(int rowNum){
    std::cout << m_pattern.at(rowNum);
}

positionCoor Location::getTilepositionCoor(){
    return m_currentCoorTile;
}

int Location::getSize(){
    return m_tiles.size();
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

objectsInTile Location::getObjectsInTile(){
    return m_currentTile->getObjectsInTile();
}

void Location::printTileMap(){
    for(int x = 0; x < int(m_tiles.size()); x++){
        for (int y = 0; y < int(m_tiles.size()); y++) {
            Tile *tile = m_tiles.at(x).at(y);
            if (m_currentCoorTile.x != x or m_currentCoorTile.y != y) {
                tile->printTile(false);
            } else {
                tile->printTile(true);
            }
        }
        std::cout << std::endl;
    }
}

int Location::getLocationLevel(){
    return m_locationLevel;
}

locationType Location::getType(){
    return m_type;
}

void Location::setType(locationType type){
    m_type = type;
}

std::string Location::getName(){
    return m_name;
}