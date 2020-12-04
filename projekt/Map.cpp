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
    renderMap();
    renderLocation();
}

void Map::setStartingLocation(){
    m_currentCoorLocation = {sizeOfMap-1,0};
    m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
}

void Map::renderMap(){
    std::vector<Location*> row1;
    std::vector<Location*> row2;
    std::vector<Location*> row3;

    row1.push_back(new Forest("Forest"));row1.push_back(new Forest("Forest"));row1.push_back(new Forest("Forest"));
    row2.push_back(new Forest("Forest"));row2.push_back(new Forest("Forest"));row2.push_back(new Forest("Forest"));
    row3.push_back(new Mountain("Mountain"));row3.push_back(new Mountain("Mountain"));row3.push_back(new Mountain("Mountain"));

    m_locations.push_back(row1);
    m_locations.push_back(row2);
    m_locations.push_back(row3);
}

void Map::renderLocation(){
    for(auto row:m_locations){
        for(auto location:row){
            location->renderLocation();
        }
    }
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
    availableMovement availableTileMovement = checkMovement(getTilepositionCoor(), int(m_currentLocation->getSize()));
    availableMovement availableLocationMovement = checkMovement(m_currentCoorLocation, sizeOfMap);

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
    availableMovement  availableTileMovement = checkMovement(m_currentLocation->getTilepositionCoor(), int(m_currentLocation->getSize()));
    availableMovement availableLocationMovement = checkMovement(m_currentCoorLocation, sizeOfMap);

    if (direction == movementDirection::N){
        if (availableTileMovement.N) {
            m_currentLocation->moveCurrentCoorTile({-1, 0});
        } else if (availableLocationMovement.N){
            std::cout << "Posun do jine lokace" << std::endl;
            m_currentCoorLocation.x--;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
            m_currentLocation->moveCurrentCoorTile({sizeOfMap - 1, 0});
        }
    } else if (direction == movementDirection::E){
        if (availableTileMovement.E){
            m_currentLocation->moveCurrentCoorTile({0, +1});
        } else if (availableLocationMovement.E){
            std::cout << "Posun do jine lokace RIGHT" << std::endl;
            m_currentCoorLocation.y++;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
            m_currentLocation->moveCurrentCoorTile({0, +1});
        }
    } else if (direction == movementDirection::S){
        if (availableTileMovement.S) {
            m_currentLocation->moveCurrentCoorTile({+1, 0});
        } else if (availableLocationMovement.S){
            std::cout << "Posun do jine lokace DOWN" << std::endl;
            m_currentCoorLocation.x++;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
            m_currentLocation->moveCurrentCoorTile({+1, 0});
        }
    } else if (direction == movementDirection::W){
        if (availableTileMovement.W) {
            m_currentLocation->moveCurrentCoorTile({0, -1});
        } else if (availableLocationMovement.W){
            std::cout << "Posun do jine lokace LEFT" << std::endl;
            m_currentCoorLocation.y--;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
            m_currentLocation->moveCurrentCoorTile({0, sizeOfMap - 1});
        }
    }
    m_currentLocation->setCurrentTile();
}

//    if(direction == movementDirection::N){
//        if(m_currentCoorTile.x-1 >= 0){
//            m_currentCoorTile.x--;
//        } else if(m_currentCoorLocation.x-1 >= 0){
//            std::cout << "Posun do jine lokace" << std::endl;
//            m_currentCoorTile.x = 2;
//            m_currentCoorLocation.x--;
//            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
//        } else {
//            std::cout << "ERROR: Posun mimo matici UP" << std::endl;
//        }
//    } else if(direction == movementDirection::E){
//        if(m_currentCoorTile.y+1 < 3){
//            m_currentCoorTile.y++;
//        } else if(m_currentCoorLocation.y+1 < sizeOfMap){
//            std::cout << "Posun do jine lokace RIGHT" << std::endl;
//            m_currentCoorTile.y = 0;
//            m_currentCoorLocation.y++;
//            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
//        } else {
//            std::cout << "ERROR: Posun mimo matici" << std::endl;
//        }
//    } else if(direction == movementDirection::S){
//        if(m_currentCoorTile.x+1 < 3){
//            m_currentCoorTile.x++;
//        } else if(m_currentCoorLocation.x+1 < sizeOfMap){
//            std::cout << "Posun do jine lokace DOWN" << std::endl;
//            m_currentCoorTile.x = 0;
//            m_currentCoorLocation.x++;
//            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
//        } else {
//            std::cout << "ERROR: Posun mimo matici DOWN" << std::endl;
//        }
//    } else if(direction == movementDirection::W){
//        if(m_currentCoorTile.y-1 >= 0){
//            m_currentCoorTile.y--;
//        } else if(m_currentCoorLocation.y-1 >= 0){
//            std::cout << "Posun do jine lokace LEFT" << std::endl;
//            m_currentCoorTile.y = 2;
//            m_currentCoorLocation.y--;
//            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
//        } else {
//            std::cout << "ERROR: Posun mimo matici LEFT" << std::endl;
//        }
//    }
//    m_currentTile = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y)->getTiles().at(m_currentCoorTile.x).at(m_currentCoorTile.y);
