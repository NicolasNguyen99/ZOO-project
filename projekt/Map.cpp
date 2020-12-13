//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Map.h"

Map::Map(){
    createMap();
    setStartingLocation();
    setStartingTile();
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
    m_currentCoorLocation = {int(m_locations.size())-1,0};
    m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
}

void Map::printTileMap(){
    m_currentLocation->printTileMap();
}

void Map::printLocationMap(){
    std::cout << "Map of locations: " << std::endl;
    for(auto row:m_locations){
        for(int i = 0; i < asciiArtRows; i++){
            for(auto location:row) {
                location->printLocation(i);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

positionCoor Map::getTilepositionCoor(){
    return m_currentLocation->getTilepositionCoor();
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
    availableMovement availableTileMovement = checkMovement(getTilepositionCoor(), m_currentLocation->getSize());
    availableMovement availableLocationMovement = checkMovement(m_currentCoorLocation, m_locations.size());

    if(availableTileMovement.N){
        std::cout << "UP in the same location" << std::endl;
    } else if(availableLocationMovement.N){
        std::cout << "UP into different location" << std::endl;
    }

    if(availableTileMovement.E){
        std::cout << "RIGHT in the same location" << std::endl;
    } else if(availableLocationMovement.E){
        std::cout << "RIGHT into different location" << std::endl;
    }

    if(availableTileMovement.S){
        std::cout << "DOWN in the same location" << std::endl;
    } else if(availableLocationMovement.S){
        std::cout << "DOWN into different location" << std::endl;
    }

    if(availableTileMovement.W){
        std::cout << "LEFT in the same location" << std::endl;
    } else if(availableLocationMovement.W){
        std::cout << "LEFT into different location" << std::endl;
    }
}

availableMovement Map::checkMovement(positionCoor coor, int range){
    return m_currentLocation->checkMovement(coor, range);
}

positionCoor Map::getCurrentCoorLocation(){
    return m_currentCoorLocation;
}

void Map::moveHeroFnc(bool avaliableTileMovement, bool availableLocationMovement, int x, int y, int moveX, int moveY){
    //prejmenovat promenne
    if(avaliableTileMovement){
        m_currentLocation->moveCurrentCoorTile({x, y});
    } else if (availableLocationMovement){
        m_currentCoorLocation.x = m_currentCoorLocation.x + x;
        m_currentCoorLocation.y = m_currentCoorLocation.y + y;
        m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
        m_currentLocation->moveCurrentCoorTile({moveX, moveY});
        std::cout << "You have moved to " << m_currentLocation->getName() << std::endl;
    }
}

void Map::moveHero(movementDirection direction) {
    availableMovement  availableTileMovement = checkMovement(m_currentLocation->getTilepositionCoor(), m_currentLocation->getSize());
    availableMovement availableLocationMovement = checkMovement(m_currentCoorLocation, m_locations.size());

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
}