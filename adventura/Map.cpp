//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Map.h"

Map::Map(mapSizes size){
    m_size = size;
    renderMap();
}

//dodelat mapa print
void Map::printMap(){
    int size = getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(m_rooms.at(i).at(j)->getIsAccessible()){
                std::cout << char(176);
                std::cout << char(176);
            } else {
                std::cout << char(219);
                std::cout << char(219);
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int Map::getSize(){
    return m_size;
}

void Map::renderSmallMap(){
    std::vector<Room*> row1;
    std::vector<Room*> row2;
    std::vector<Room*> row3;
    std::vector<Room*> row4;

    row1.push_back(new Room(true));
    row1.push_back(new Room(true));
    row1.push_back(new Room(true));
    row1.push_back(new Room(true));

    row2.push_back(new Room(false));
    row2.push_back(new Room(false));
    row2.push_back(new Room(false));
    row2.push_back(new Room(false));

    row3.push_back(new Room(true));
    row3.push_back(new Room(true));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));

    row4.push_back(new Room(true));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(true));

    m_rooms.push_back(row1);
    m_rooms.push_back(row2);
    m_rooms.push_back(row3);
    m_rooms.push_back(row4);
}

void Map::renderMediumMap(){
    std::vector<Room*> row1;
    std::vector<Room*> row2;
    std::vector<Room*> row3;
    std::vector<Room*> row4;
    std::vector<Room*> row5;

    row1.push_back(new Room(false));
    row1.push_back(new Room(false));
    row1.push_back(new Room(false));
    row1.push_back(new Room(false));
    row1.push_back(new Room(false));

    row2.push_back(new Room(false));
    row2.push_back(new Room(false));
    row2.push_back(new Room(false));
    row2.push_back(new Room(false));
    row2.push_back(new Room(false));

    row3.push_back(new Room(false));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));

    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));

    row5.push_back(new Room(false));
    row5.push_back(new Room(false));
    row5.push_back(new Room(false));
    row5.push_back(new Room(false));
    row5.push_back(new Room(false));

    m_rooms.push_back(row1);
    m_rooms.push_back(row2);
    m_rooms.push_back(row3);
    m_rooms.push_back(row4);
    m_rooms.push_back(row5);
}

void Map::renderLargeMap(){
    std::vector<Room*> row1;
    std::vector<Room*> row2;
    std::vector<Room*> row3;
    std::vector<Room*> row4;
    std::vector<Room*> row5;
    std::vector<Room*> row6;

    row1.push_back(new Room(false));
    row1.push_back(new Room(false));
    row1.push_back(new Room(false));
    row1.push_back(new Room(false));
    row1.push_back(new Room(false));
    row1.push_back(new Room(false));

    row2.push_back(new Room(false));
    row2.push_back(new Room(false));
    row2.push_back(new Room(false));
    row2.push_back(new Room(false));
    row2.push_back(new Room(false));
    row2.push_back(new Room(false));

    row3.push_back(new Room(false));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));

    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));

    row5.push_back(new Room(false));
    row5.push_back(new Room(false));
    row5.push_back(new Room(false));
    row5.push_back(new Room(false));
    row5.push_back(new Room(false));
    row5.push_back(new Room(false));

    row6.push_back(new Room(false));
    row6.push_back(new Room(false));
    row6.push_back(new Room(false));
    row6.push_back(new Room(false));
    row6.push_back(new Room(false));
    row6.push_back(new Room(false));

    m_rooms.push_back(row1);
    m_rooms.push_back(row2);
    m_rooms.push_back(row3);
    m_rooms.push_back(row4);
    m_rooms.push_back(row5);
    m_rooms.push_back(row6);
}

void Map::renderMap() {
    int size = getSize();
    if(size == XS){
        renderSmallMap();
    } else {
        if(size == M){
            renderMediumMap();
        } else {
            if(size == L){
                renderLargeMap();
            }
        }
    }
    //vyber pocatecni mistnosti v levem spodnim rohu matice
    setCurrentRoom(m_rooms.at(size-1).at(0));
    //ulozeni souradnice pocatecni mistnosti
    setCurrentCoor(positionCoor{size-1, 0});
}

Room* Map::getCurrentRoom(){
    return m_currentRoom;
}

positionCoor Map::getCurrentCoor(){
    return m_currentCoor;
}

std::vector<std::vector<Room*>> Map::getRooms(){
    return m_rooms;
};

void Map::printMovementOptions(){
    if(m_currentCoor.x+1 < m_size and m_rooms.at(m_currentCoor.x+1).at(m_currentCoor.y)->getIsAccessible()){
        std::cout << "You can go down" << std::endl;
    }
    if(m_currentCoor.x-1 < m_size and m_currentCoor.x-1 >= 0 and m_rooms.at(m_currentCoor.x-1).at(m_currentCoor.y)->getIsAccessible()){
        std::cout << "You can go up" << std::endl;
    }
    if(m_currentCoor.y+1 < m_size and m_rooms.at(m_currentCoor.x).at(m_currentCoor.y+1)->getIsAccessible()){
        std::cout << "You can go right" << std::endl;
    }
    if(m_currentCoor.y-1 < m_size and m_currentCoor.y-1 >= 0 and m_rooms.at(m_currentCoor.x).at(m_currentCoor.y-1)->getIsAccessible()){
        std::cout << "You can go left" << std::endl;
    }
}

void Map::setCurrentCoor(positionCoor currentCoor){
    m_currentCoor.x = currentCoor.x;
    m_currentCoor.y = currentCoor.y;
}

void Map::setCurrentRoom(Room* currentRoom){
    m_currentRoom = currentRoom;
}