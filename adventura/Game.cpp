//
// Created by Nicolas Nguyen on 19/11/2020.
//

#include "Game.h"

Game::Game(){
    m_map = new Map(XS);
    m_team = new Team();
}

void Game::printMap(){
    m_map->printMap();
}

void Game::printMovementOptions(){
    m_map->printMovementOptions();
}

void Game::moveTeam(movementDirection direction){
    std::vector<std::vector<Room*>> map = (m_map->getRooms());
    Room* currentRoom = m_map->getCurrentRoom();
    positionCoor currentCoor = m_map->getCurrentCoor();

    m_team->moveTeam(map,currentRoom, currentCoor, direction);

    m_map->setCurrentCoor(currentCoor);
    m_map->setCurrentRoom(currentRoom);
}

positionCoor Game::getCurrentCoor(){
    return m_map->getCurrentCoor();
}