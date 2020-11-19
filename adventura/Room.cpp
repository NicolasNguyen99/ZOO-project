//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Room.h"

Room::Room(bool isAccessible, Enemy* enemy){
    m_isExplored = false;
}

Room::Room():Room(false, nullptr){}

Room::Room(Enemy* enemy):Room(true, enemy){}

Room::Room(bool isAccessible):Room(isAccessible, nullptr){}

bool Room::getIsAccessible(){
    return m_isAccessible;
}

bool Room::getIsExplored(){
    return m_isExplored;
}