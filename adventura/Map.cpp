//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Map.h"
//dodelat mapa print
void Map::printMap(){
    int size = getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
//            std::cout << m_rooms.at(i).at(j)->getIsAccessible();
//            std::cout << m_rooms.at(i).at(j)->getIsExplored() << " ";
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

    row3.push_back(new Room(false));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));
    row3.push_back(new Room(false));

    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));
    row4.push_back(new Room(false));

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
    m_currentRoom = m_rooms.at(size-1).at(0);
    //ulozeni souradnic pocatecni mistnosti
    m_currentCoor[0] = size-1;
    m_currentCoor[1] = 0;
}

//pridelit hotovy team
Map::Map(mapSizes size){
    m_size = size;
    renderMap();
    m_team = new Team();
}

Room* Map::getCurrentRoom(){
    return m_currentRoom;
}

std::array<int, 2> Map::getCurrentCoor(){
    return m_currentCoor;
}

//rozdelit do vice metod
void Map::printMovementOptions(){
    if(m_currentCoor[0]+1 < m_size and !m_rooms.at(m_currentCoor[0]+1).at(m_currentCoor[1])->getIsAccessible()){
        std::cout << "You can go down" << std::endl;
    }
    if(m_currentCoor[0]-1 < m_size and m_currentCoor[0]-1 >= 0 and !m_rooms.at(m_currentCoor[0]-1).at(m_currentCoor[1])->getIsAccessible()){
        std::cout << "You can go up" << std::endl;
    }
    if(m_currentCoor[1]+1 < m_size and !m_rooms.at(m_currentCoor[0]).at(m_currentCoor[1]+1)->getIsAccessible()){
        std::cout << "You can go right" << std::endl;
    }
    if(m_currentCoor[1]-1 < m_size and m_currentCoor[1]-1 >= 0 and !m_rooms.at(m_currentCoor[0]).at(m_currentCoor[1]-1)->getIsAccessible()){
        std::cout << "You can go left" << std::endl;
    }
}

void Map::moveTeam(movementDirection direction){
//   N x-- y=y
//   E x=x y++
//   S x++ y=y
//   W x=x y--
    if(direction == N){
        m_currentCoor[0] = getCurrentCoor().at(0)-1;
        m_currentRoom = m_rooms.at(m_currentCoor[0]).at(m_currentCoor[1]);
    } else {
        if(direction == E){
            m_currentCoor[1] = getCurrentCoor().at(0)+1;
            m_currentRoom = m_rooms.at(m_currentCoor[0]).at(m_currentCoor[1]);
        } else {
            if(direction == S){
                m_currentCoor[0] = getCurrentCoor().at(0)+1;
                m_currentRoom = m_rooms.at(m_currentCoor[0]).at(m_currentCoor[1]);
            } else {
                if(direction == W) {
                    m_currentCoor[1] = getCurrentCoor().at(0) - 1;
                    m_currentRoom = m_rooms.at(m_currentCoor[0]).at(m_currentCoor[1]);
                }
            }
        }
    }
}