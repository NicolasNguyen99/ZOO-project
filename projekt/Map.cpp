//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Map.h"

Map::Map(){

}

void Map::renderSmallMap(){
    std::vector<Location*> row1;
    std::vector<Location*> row2;
    std::vector<Location*> row3;

    row1.push_back(new Forest());row1.push_back(new Forest());row1.push_back(new Forest());
    row2.push_back(new Forest());row2.push_back(new Forest());row2.push_back(new Forest());
    row3.push_back(new Mountain());row3.push_back(new Mountain());row3.push_back(new Mountain());

    m_locations.push_back(row1);
    m_locations.push_back(row2);
    m_locations.push_back(row3);
    m_currentLocation = m_locations.at(2).at(0);
    m_currentCoorLocation = {2,0};
    m_size = sizeOfMap::Small;
}

void Map::renderLocation(){
    for(auto row:m_locations){
        for(auto location:row){
            location->renderLocation();
        }
    }
    m_currentTile = m_locations.at(2).at(0)->getTiles().at(2).at(0);
    m_currentCoorTile = {2,0};
}

void Map::printLocationMap(){
    std::cout << "Map of locations: ";
    for(auto row:m_locations){
        for(int i = 0; i < 5; i++){
            for(auto location:row) {
                location->printLocation(i);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Map::printMovementOptions(){
    if(m_currentCoorTile.x-1 >= 0){
        std::cout << "UP in the same location" << std::endl;
    } else if(m_currentCoorLocation.x-1 >= 0){
        std::cout << "UP into different location" << std::endl;
    }

    if(m_currentCoorTile.y+1 < 3){
        std::cout << "RIGHT in the same location" << std::endl;
    } else if(m_currentCoorLocation.y+1 < int(m_size)){
        std::cout << "RIGHT into different location" << std::endl;
    }

    if(m_currentCoorTile.x+1 < 3){
        std::cout << "DOWN in the same location" << std::endl;
    } else if(m_currentCoorLocation.x+1 < int(m_size)){
        std::cout << "DOWN into different location" << std::endl;
    }

    if(m_currentCoorTile.y-1 >= 0){
        std::cout << "LEFT in the same location" << std::endl;
    } else if(m_currentCoorLocation.y-1 >= 0){
        std::cout << "LEFT into different location" << std::endl;
    }
}

void Map::printTileMap(){
    std::cout << "Tile map: " << std::endl;
    m_currentLocation->printTileMap(m_currentCoorTile);
}

void Map::moveHero(movementDirection direction){
    if(direction == movementDirection::N){
        if(m_currentCoorTile.x-1 >= 0){
            m_currentCoorTile.x--;
        } else if(m_currentCoorLocation.x-1 >= 0){
            std::cout << "Posun do jine lokace" << std::endl;
            m_currentCoorTile.x = 2;
            m_currentCoorLocation.x--;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
        } else {
            std::cout << "ERROR: Posun mimo matici UP" << std::endl;
        }
    } else if(direction == movementDirection::E){
        if(m_currentCoorTile.y+1 < 3){
            m_currentCoorTile.y++;
        } else if(m_currentCoorLocation.y+1 < 2){
            std::cout << "Posun do jine lokace RIGHT" << std::endl;
            m_currentCoorTile.y = 0;
            m_currentCoorLocation.y++;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
        } else {
            std::cout << "ERROR: Posun mimo matici" << std::endl;
        }
    } else if(direction == movementDirection::S){
        if(m_currentCoorTile.x+1 < 3){
            m_currentCoorTile.x++;
        } else if(m_currentCoorLocation.x+1 < 2){
            std::cout << "Posun do jine lokace DOWN" << std::endl;
            m_currentCoorTile.x = 0;
            m_currentCoorLocation.x++;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
        } else {
            std::cout << "ERROR: Posun mimo matici DOWN" << std::endl;
        }
    } else if(direction == movementDirection::W){
        if(m_currentCoorTile.y-1 >= 0){
            m_currentCoorTile.y--;
        } else if(m_currentCoorLocation.y-1 >= 0){
            std::cout << "Posun do jine lokace LEFT" << std::endl;
            m_currentCoorTile.y = 2;
            m_currentCoorLocation.y--;
            m_currentLocation = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y);
        } else {
            std::cout << "ERROR: Posun mimo matici LEFT" << std::endl;
        }
    }
    m_currentTile = m_locations.at(m_currentCoorLocation.x).at(m_currentCoorLocation.y)->getTiles().at(m_currentCoorTile.x).at(m_currentCoorTile.y);
}