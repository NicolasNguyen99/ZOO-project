//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Map.h"

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
    if(size == S){
        renderSmallMap(size);
    } else {
        if(size == M){
            renderMediumMap(size);
        } else {
            renderLargeMap(size);
        }
    }
}

Map::Map(mapSizes size){
    m_size = size;
    renderMap(size);
}