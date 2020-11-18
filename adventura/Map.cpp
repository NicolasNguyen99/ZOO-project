//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Map.h"
//predelat int size na getSize, nepredavat argumentem
void Map::printMap(int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << m_rooms.at(i).at(j)->getIsAccessible();
            std::cout << m_rooms.at(i).at(j)->getIsExplored() << " ";
        }
        std::cout << std::endl;
    }
}

void Map::renderSmallMap(int size){
    std::vector<Room*> row1;
    std::vector<Room*> row2;
    std::vector<Room*> row3;

    row1.push_back(new Room(1));
    row1.push_back(new Room(1));
    row1.push_back(new Room(1));

    row2.push_back(new Room(0));
    row2.push_back(new Room(0));
    row2.push_back(new Room(1));

    row3.push_back(new Room(0));
    row3.push_back(new Room(1));
    row3.push_back(new Room(1));

    m_rooms.push_back(row1);
    m_rooms.push_back(row2);
    m_rooms.push_back(row3);
}

void Map::renderMediumMap(int size){
    std::vector<Room*> row1;
    std::vector<Room*> row2;
    std::vector<Room*> row3;
    std::vector<Room*> row4;

    row1.push_back(new Room(1));
    row1.push_back(new Room(1));
    row1.push_back(new Room(1));
    row1.push_back(new Room(1));

    row2.push_back(new Room(0));
    row2.push_back(new Room(0));
    row2.push_back(new Room(1));
    row2.push_back(new Room(1));

    row3.push_back(new Room(0));
    row3.push_back(new Room(1));
    row3.push_back(new Room(1));
    row3.push_back(new Room(1));

    row4.push_back(new Room(0));
    row4.push_back(new Room(1));
    row4.push_back(new Room(1));
    row4.push_back(new Room(1));

    m_rooms.push_back(row1);
    m_rooms.push_back(row2);
    m_rooms.push_back(row3);
    m_rooms.push_back(row4);
}

void Map::renderLargeMap(int size){
    std::vector<Room*> row1;
    std::vector<Room*> row2;
    std::vector<Room*> row3;
    std::vector<Room*> row4;
    std::vector<Room*> row5;

    row1.push_back(new Room(1));
    row1.push_back(new Room(1));
    row1.push_back(new Room(1));
    row1.push_back(new Room(1));
    row1.push_back(new Room(1));

    row2.push_back(new Room(0));
    row2.push_back(new Room(0));
    row2.push_back(new Room(1));
    row2.push_back(new Room(1));
    row2.push_back(new Room(1));

    row3.push_back(new Room(0));
    row3.push_back(new Room(1));
    row3.push_back(new Room(1));
    row3.push_back(new Room(1));
    row3.push_back(new Room(1));

    row4.push_back(new Room(0));
    row4.push_back(new Room(1));
    row4.push_back(new Room(1));
    row4.push_back(new Room(1));
    row4.push_back(new Room(1));

    row5.push_back(new Room(1));
    row5.push_back(new Room(1));
    row5.push_back(new Room(1));
    row5.push_back(new Room(1));
    row5.push_back(new Room(1));

    m_rooms.push_back(row1);
    m_rooms.push_back(row2);
    m_rooms.push_back(row3);
    m_rooms.push_back(row4);
    m_rooms.push_back(row5);
}

void Map::renderMap(int size) {
    if(size == XS){
        renderSmallMap(size);
    } else {
        if(size == M){
            renderMediumMap(size);
        } else {
            renderLargeMap(size);
        }
    }
    m_currentRoom = m_rooms.at(size-1).at(0);
    m_currentCoor[0] = size-1;
    m_currentCoor[1] = 0;
}

Map::Map(mapSizes size){
    m_size = size;
    renderMap(size);
    m_team = new Team();
}

Room* Map::getCurrentRoom(){
    return m_currentRoom;
}

std::array<int, 2> Map::getCurrentCoor(){
    return m_currentCoor;
}

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
                m_currentCoor[1] = getCurrentCoor().at(0)-1;
                m_currentRoom = m_rooms.at(m_currentCoor[0]).at(m_currentCoor[1]);
            }
        }
    }
}