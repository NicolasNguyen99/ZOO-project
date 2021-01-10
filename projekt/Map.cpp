//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Map.h"

Map::Map(){
    createMap();
    setStartingLocation();
    setStartingTile();
}

void Map::removeChest(){
    m_currentLocation->removeChest();
}

void Map::killEnemy(){
    m_currentLocation->killEnemy();
}

void Map::createMap(){
    std::vector<Location*> row1;
    std::vector<Location*> row2;
    std::vector<Location*> row3;

    LocationDirector* director = new LocationDirector(new ForestLocationBuilder());
    row1.push_back(director->createLocation());
    director->setBuilder(new MountainLocationBuilder());
    row1.push_back(director->createLocation());
    director->setBuilder(new SwampLocationBuilder());
    row1.push_back(director->createLocation());
    director->setBuilder(new CastleLocationBuilder());
    row2.push_back(director->createLocation());
    director->setBuilder(new DesertLocationBuilder());
    row2.push_back(director->createLocation());
    director->setBuilder(new HellLocationBuilder());
    row2.push_back(director->createLocation());
    director->setBuilder(new HeavenLocationBuilder());
    row3.push_back(director->createLocation());
    director->setBuilder(new CaveLocationBuilder());
    row3.push_back(director->createLocation());
    director->setBuilder(new PlainLocationBuilder());
    row3.push_back(director->createLocation());

    m_locations.push_back(row1);
    m_locations.push_back(row2);
    m_locations.push_back(row3);
}

void Map::setStartingLocation(){
    m_currentLocationCoor = {int(m_locations.size())-1,0};
    m_currentLocation = m_locations.at(m_currentLocationCoor.x).at(m_currentLocationCoor.y);
}

void Map::printTileMap(){
    m_currentLocation->printTileMap();
}

void Map::printLocationMap(){
    std::cout << "Map of locations: " << std::endl;
    for(auto row:m_locations){
        for(int i = 0; i < asciiArtRows; i++){
            for(auto location:row) {
                std::cout << "     ";
                location->printLocation(i);
                std::cout << "     ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

positionCoor Map::getTilePositionCoor(){
    return m_currentLocation->getTilepositionCoor();
}

void Map::printEnemyStats(){
    m_currentLocation->printEnemyStats();
}

void Map::setStartingTile(){
    m_currentLocation->setStartingTile();
}

Enemy* Map::getEnemy(){
    return m_currentLocation->getEnemy();
}

objectsInTile Map::getObjectsInTile(){
    return m_currentLocation->getObjectsInTile();
}

void Map::printMovementOptions(){
    availableMovement availableTileMovement = checkMovement(getTilePositionCoor(), m_currentLocation->getSize());
    availableMovement availableLocationMovement = checkMovement(m_currentLocationCoor, m_locations.size());

    if(availableTileMovement.N){
        std::cout << "[N] UP in the same location" << std::endl;
    } else if(availableLocationMovement.N){
        std::cout << "[N] UP into different location" << std::endl;
    }

    if(availableTileMovement.E){
        std::cout << "[E] RIGHT in the same location" << std::endl;
    } else if(availableLocationMovement.E){
        std::cout << "[E] RIGHT into different location" << std::endl;
    }

    if(availableTileMovement.S){
        std::cout << "[S] DOWN in the same location" << std::endl;
    } else if(availableLocationMovement.S){
        std::cout << "[S] DOWN into different location" << std::endl;
    }

    if(availableTileMovement.W){
        std::cout << "[W] LEFT in the same location" << std::endl;
    } else if(availableLocationMovement.W){
        std::cout << "[W] LEFT into different location" << std::endl;
    }
}

availableMovement Map::checkMovement(positionCoor coor, int range){
    return m_currentLocation->checkMovement(coor, range);
}

void Map::moveHeroFnc(bool avaliableTileMovement, bool availableLocationMovement, int x, int y, int moveX, int moveY){
    //prejmenovat promenne
    if(avaliableTileMovement){
        m_currentLocation->moveCurrentCoorTile({x, y});
    } else if (availableLocationMovement){
        m_currentLocationCoor.x = m_currentLocationCoor.x + x;
        m_currentLocationCoor.y = m_currentLocationCoor.y + y;
        m_currentLocation = m_locations.at(m_currentLocationCoor.x).at(m_currentLocationCoor.y);
        m_currentLocation->moveCurrentCoorTile({moveX, moveY});
        std::cout << "You have moved to " << m_currentLocation->getName() << std::endl;
    }
}

void Map::moveHero(movementDirection direction){
    m_previousMovement = direction;
    availableMovement  availableTileMovement = checkMovement(m_currentLocation->getTilepositionCoor(), m_currentLocation->getSize());
    availableMovement availableLocationMovement = checkMovement(m_currentLocationCoor, m_locations.size());

    if(direction == movementDirection::N) {
        moveHeroFnc(availableTileMovement.N, availableLocationMovement.N, -1, 0, int(m_locations.size()) - 1, 0);
    } else if(direction == movementDirection::E) {
        moveHeroFnc(availableTileMovement.E, availableLocationMovement.E, 0, 1, 0, 1);
    } else if(direction == movementDirection::S){
        moveHeroFnc(availableTileMovement.S, availableLocationMovement.S, 1, 0, 1, 0);
    } else if (direction == movementDirection::W) {
        moveHeroFnc(availableTileMovement.W, availableLocationMovement.W, 0, -1, 0, int(m_locations.size()) - 1);
    }
    m_currentLocation->setCurrentTile();
    m_currentLocation->setTileExploration();
}

movementDirection Map::getPreviousMovement(){
    return m_previousMovement;
}