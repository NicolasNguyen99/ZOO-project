//
// Created by Nicolas Nguyen on 01/12/2020.
//
#include "Location.h"

Location::Location(std::string name, int level){
    m_name = name;
    m_locationLevel = level;
}

positionCoor Location::s_currentCoorTile;

weaponBonusLocation Location::getBonusOfLocation(){
    return m_bonusOfLocation;
}

void Location::setBonusOfLocation(weaponBonusLocation bonus){
    m_bonusOfLocation = bonus;
}

void Location::setTiles(MatrixOfTiles tiles){
    m_tiles = tiles;
}

void Location::setPattern(MatrixOfAsciiArt rowPattern){
    m_pattern = rowPattern;
}

Enemy* Location::getEnemy(){
    return m_currentTile->getEnemy();
}

void Location::printEnemyStats(){
    m_currentTile->printEnemyStats();
}

void Location::setStartingTile(){
    s_currentCoorTile = {int(m_tiles.size())-1,0};
    setCurrentTile();
    setTileExploration();
}

void Location::setTileExploration(){
    availableMovement availableTileMovement = checkMovement(s_currentCoorTile, m_tiles.size());
    if(!m_currentTile->getIsExplored()){
        m_currentTile->setIsExplored();
    }
    if(availableTileMovement.N and !m_tiles.at(s_currentCoorTile.x-1).at(s_currentCoorTile.y)->getIsExplored()){
        m_tiles.at(s_currentCoorTile.x-1).at(s_currentCoorTile.y)->setIsExplored();
    }
    if(availableTileMovement.E and !m_tiles.at(s_currentCoorTile.x).at(s_currentCoorTile.y+1)->getIsExplored()){
        m_tiles.at(s_currentCoorTile.x).at(s_currentCoorTile.y+1)->setIsExplored();
    }
    if(availableTileMovement.S and  !m_tiles.at(s_currentCoorTile.x+1).at(s_currentCoorTile.y)->getIsExplored()){
        m_tiles.at(s_currentCoorTile.x+1).at(s_currentCoorTile.y)->setIsExplored();
    }
    if(availableTileMovement.W and !m_tiles.at(s_currentCoorTile.x).at(s_currentCoorTile.y-1)->getIsExplored()){
        m_tiles.at(s_currentCoorTile.x).at(s_currentCoorTile.y-1)->setIsExplored();
    }
}

void Location::moveCurrentCoorTile(sizeOfMovement sizePosition){
    s_currentCoorTile.x = (s_currentCoorTile.x + sizePosition.x)%(int(m_tiles.size()));
    s_currentCoorTile.y = (s_currentCoorTile.y + sizePosition.y)%(int(m_tiles.size()));
}

void Location::setCurrentTile(){
    m_currentTile = m_tiles.at(s_currentCoorTile.x).at(s_currentCoorTile.y);
}

void Location::printLocation(int rowNum){
    std::cout << m_pattern.at(rowNum);
}

positionCoor Location::getTilepositionCoor(){
    return s_currentCoorTile;
}

int Location::getSize(){
    return m_tiles.size();
}

void Location::killEnemy(){
    m_currentTile->killEnemy();
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

void Location::removeChest(){
    m_currentTile->removeChest();
}

void Location::printTileMap(TileStrip topStrip, TileStrip bottomStrip, TileStrip rightStrip, TileStrip leftStrip){
    std::cout << "Tile map: \n";
    std::cout << "|";
    if(leftStrip.at(0) != nullptr){
        std::cout << "          ";
    }
    for(auto tile:topStrip){
        if(tile != nullptr){
            tile->printTile(false);
        }
    }
    std::cout << "|";
    std::cout << "\n|------------------------------|\n";
    for(int x = 0; x < int(m_tiles.size()); x++){
        std::cout << "|";
        if(leftStrip.at(x) != nullptr){
            leftStrip.at(x)->printTile(false);
        }
        for(int y = 0; y < int(m_tiles.size()); y++) {
            Tile *tile = m_tiles.at(x).at(y);
            if (s_currentCoorTile.x != x or s_currentCoorTile.y != y) {
                tile->printTile(false);
            } else {
                tile->printTile(true);
            }
        }
        std::cout << "|";
        if(rightStrip.at(x) != nullptr){
            rightStrip.at(x)->printTile(false);
        }
        std::cout << "\n";
    }
    std::cout << "|------------------------------|\n";
    std::cout << "|";
    if(leftStrip.at(0) != nullptr){
        std::cout << "          ";
    }
    for(auto tile:bottomStrip){
        if(tile != nullptr){
            tile->printTile(false);
        }
    }
    std::cout << "|";
    std::cout << "\n";
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

MatrixOfTiles Location::getTiles(){
    return m_tiles;
}