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

    LocationDirector* director = new LocationDirector(new ForestLocationBuilder);

    row1.push_back(director->createLocation());
    row1.push_back(director->createLocation());
    row1.push_back(director->createLocation());

    director->setBuilder(new MountainLocationBuilder);
    row2.push_back(director->createLocation());
    row2.push_back(director->createLocation());
    row2.push_back(director->createLocation());

    row3.push_back(director->createLocation());
    row3.push_back(director->createLocation());
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
    std::cout << "Map of locations: ";
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

void Map::moveHero(movementDirection direction) {
    availableMovement  availableTileMovement = checkMovement(m_currentLocation->getTilepositionCoor(), m_currentLocation->getSize());
    availableMovement availableLocationMovement = checkMovement(m_currentCoorLocation, m_locations.size());

    if (direction == movementDirection::N){
        if (availableTileMovement.N) {
            m_currentLocation->moveCurrentCoorTile({-1, 0});
        } else if (availableLocationMovement.N){
            std::cout << "Posun do jine lokace" << std::endl;
            m_currentCoorLocation.x--;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
            m_currentLocation->moveCurrentCoorTile({int(m_locations.size()) - 1, 0});
            std::cout << m_currentLocation->getName() << std::endl;
        }
    } else if (direction == movementDirection::E){
        if (availableTileMovement.E){
            m_currentLocation->moveCurrentCoorTile({0, +1});
        } else if (availableLocationMovement.E){
            std::cout << "Posun do jine lokace RIGHT" << std::endl;
            m_currentCoorLocation.y++;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
            m_currentLocation->moveCurrentCoorTile({0, +1});
            std::cout << m_currentLocation->getName() << std::endl;
        }
    } else if (direction == movementDirection::S){
        if (availableTileMovement.S) {
            m_currentLocation->moveCurrentCoorTile({+1, 0});
        } else if (availableLocationMovement.S){
            std::cout << "Posun do jine lokace DOWN" << std::endl;
            m_currentCoorLocation.x++;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
            m_currentLocation->moveCurrentCoorTile({+1, 0});
            std::cout << m_currentLocation->getName() << std::endl;
        }
    } else if (direction == movementDirection::W){
        if (availableTileMovement.W) {
            m_currentLocation->moveCurrentCoorTile({0, -1});
        } else if (availableLocationMovement.W){
            std::cout << "Posun do jine lokace LEFT" << std::endl;
            m_currentCoorLocation.y--;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
            m_currentLocation->moveCurrentCoorTile({0, int(m_locations.size())-1});
            std::cout << m_currentLocation->getName() << std::endl;
        }
    }
    m_currentLocation->setCurrentTile();
}