//
// Created by Kristina Nazarjanová on 23/11/2020.
//

#include "Map.h"
Map::Map(mapSize size){
    m_size = size;
    createMap();
}

void Map::renderSmallMap(){
    std::vector<Tile*> row1;
    std::vector<Tile*> row2;
    std::vector<Tile*> row3;
    std::vector<Tile*> row4;

    row1.push_back(new Forrest(tileType::Forrest));row1.push_back(new Swamp(tileType::Swamp));row1.push_back(new Mountain(tileType::Mountain));row1.push_back(new Mountain(tileType::Mountain));
    row2.push_back(new Forrest(tileType::Forrest));row2.push_back(new Swamp(tileType::Swamp));row2.push_back(new Mountain(tileType::Mountain));row2.push_back(new Mountain(tileType::Mountain));
    row3.push_back(new Forrest(tileType::Forrest));row3.push_back(new Swamp(tileType::Swamp));row3.push_back(new Mountain(tileType::Mountain));row3.push_back(new Mountain(tileType::Mountain));
    row4.push_back(new Forrest(tileType::Forrest));row4.push_back(new Swamp(tileType::Swamp));row4.push_back(new Mountain(tileType::Mountain));row4.push_back(new Mountain(tileType::Mountain));

    m_tiles.push_back(row1);
    m_tiles.push_back(row2);
    m_tiles.push_back(row3);
    m_tiles.push_back(row4);
}

void Map::renderMediumMap(){
    std::vector<Tile*> row1;
    std::vector<Tile*> row2;
    std::vector<Tile*> row3;
    std::vector<Tile*> row4;
    std::vector<Tile*> row5;

    row1.push_back(new Forrest(tileType::Forrest));row1.push_back(new Swamp(tileType::Swamp));row1.push_back(new Mountain(tileType::Mountain));row1.push_back(new Mountain(tileType::Mountain));row1.push_back(new Mountain(tileType::Mountain));
    row2.push_back(new Forrest(tileType::Forrest));row2.push_back(new Swamp(tileType::Swamp));row2.push_back(new Mountain(tileType::Mountain));row2.push_back(new Mountain(tileType::Mountain));row2.push_back(new Mountain(tileType::Mountain));
    row3.push_back(new Forrest(tileType::Forrest));row3.push_back(new Swamp(tileType::Swamp));row3.push_back(new Mountain(tileType::Mountain));row3.push_back(new Mountain(tileType::Mountain));row3.push_back(new Mountain(tileType::Mountain));
    row4.push_back(new Forrest(tileType::Forrest));row4.push_back(new Swamp(tileType::Swamp));row4.push_back(new Mountain(tileType::Mountain));row4.push_back(new Mountain(tileType::Mountain));row4.push_back(new Mountain(tileType::Mountain));
    row5.push_back(new Forrest(tileType::Forrest));row5.push_back(new Swamp(tileType::Swamp));row5.push_back(new Mountain(tileType::Mountain));row5.push_back(new Mountain(tileType::Mountain));row5.push_back(new Mountain(tileType::Mountain));

    m_tiles.push_back(row1);
    m_tiles.push_back(row2);
    m_tiles.push_back(row3);
    m_tiles.push_back(row4);
    m_tiles.push_back(row5);
}

void Map::renderLargeMap(){

}

void Map::createMap(){
    if(m_size == mapSize::Small){
        renderSmallMap();
    } else if(m_size == mapSize::Medium){
        renderMediumMap();
    } else if(m_size == mapSize::Large){
        renderLargeMap();
    } else {
        std::cout << "Neznama velikost mapy" << std::endl;
    }
    setCurrentCoor(positionCoor{int(m_size)-1, 0});
    setCurrentTile(m_tiles.at(m_currentCoor.x).at(m_currentCoor.y));
}

positionCoor Map::getCurrentCoor(){
    return m_currentCoor;
}

//matrixOfTiles Map::getTiles(){
//
//}

void Map::moveHero(movementDirection direction){
//   N x-- y=y E x=x y++ S x++ y=y W x=x y--
    if(direction == movementDirection::N){
        m_currentCoor.x--;
        m_currentTile = m_tiles.at(m_currentCoor.x).at(m_currentCoor.y);
    } else {
        if(direction == movementDirection::E){
            m_currentCoor.y++;
            m_currentTile = m_tiles.at(m_currentCoor.x).at(m_currentCoor.y);
        } else {
            if(direction == movementDirection::S){
                m_currentCoor.x++;
                m_currentTile = m_tiles.at(m_currentCoor.x).at(m_currentCoor.y);
            } else {
                if(direction == movementDirection::W) {
                    m_currentCoor.y--;
                    m_currentTile = m_tiles.at(m_currentCoor.x).at(m_currentCoor.y);
                }
            }
        }
    }
}

mapSize Map::getSize(){
    return m_size;
}

Tile* Map::getCurrentTile(){
    return m_currentTile;
}

void Map::setCurrentCoor(positionCoor currentCoor){
    m_currentCoor.x = currentCoor.x;
    m_currentCoor.y = currentCoor.y;
}

void Map::setCurrentTile(Tile* currentTile){
    m_currentTile = currentTile;
}

void Map::printMap(){
    for(auto row:m_tiles){
        for(int i = 0; i < 5; i++){
            for(auto tile:row){
                tile->printPattern(i);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Map::printMovementOptions(){
    if(m_currentCoor.x+1 < int(m_size) and !m_tiles.at(m_currentCoor.x+1).at(m_currentCoor.y)->getIsLocked()){
        std::cout << "You can go down" << std::endl;
    }
    if(m_currentCoor.x-1 < int(m_size) and m_currentCoor.x-1 >= 0 and !m_tiles.at(m_currentCoor.x-1).at(m_currentCoor.y)->getIsLocked()){
        std::cout << "You can go up" << std::endl;
    }
    if(m_currentCoor.y+1 < int(m_size) and !m_tiles.at(m_currentCoor.x).at(m_currentCoor.y+1)->getIsLocked()){
        std::cout << "You can go right" << std::endl;
    }
    if(m_currentCoor.y-1 < int(m_size) and m_currentCoor.y-1 >= 0 and !m_tiles.at(m_currentCoor.x).at(m_currentCoor.y-1)->getIsLocked()){
        std::cout << "You can go left" << std::endl;
    }
}