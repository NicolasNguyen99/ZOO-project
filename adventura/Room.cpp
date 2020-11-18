//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Room.h"

Room::Room(bool isAccessible){
    m_isAccessible = isAccessible;
    m_isExplored = false;
}

bool Room::getIsAccessible(){
    return m_isAccessible;
}

bool Room::getIsExplored(){
    return m_isExplored;
}

Room::Room():Room(false){}