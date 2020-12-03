//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Game.h"

Game::Game(){
    setUpGame();
}

void Game::printLocationMap(){
    m_map->printLocationMap();
}

void Game::printTileMap(){
    m_map->printTileMap();
}

void Game::setUpGame(){
    createMap();
    createHero();
}

void Game::createHero(){
    m_map->createHero();
}

void Game::createMap(){
    m_map = new Map();
    m_map->createMap();

    printLocationMap();
    std::cout << std::endl;

    std::cout << "Tile map: " << std::endl;
    printTileMap();
    std::cout << "Location coor: " << m_map->m_currentCoorLocation.x << m_map->m_currentCoorLocation.y << std::endl;
    std::cout << "Tile coor: " << m_map->m_currentCoorTile.x << m_map->m_currentCoorTile.y << std::endl;
    std::cout << std::endl;
    printMovementOptions();
    std::cout << std::endl;
    moveHero(movementDirection::N);

    std::cout << "Tile map: " << std::endl;
    printTileMap();
    std::cout << "Location coor: " << m_map->m_currentCoorLocation.x << m_map->m_currentCoorLocation.y << std::endl;
    std::cout << "Tile coor: " << m_map->m_currentCoorTile.x << m_map->m_currentCoorTile.y << std::endl;
    std::cout << std::endl;
    printMovementOptions();
    std::cout << std::endl;
    moveHero(movementDirection::N);

    std::cout << "Tile map: " << std::endl;
    printTileMap();
    std::cout << "Location coor: " << m_map->m_currentCoorLocation.x << m_map->m_currentCoorLocation.y << std::endl;
    std::cout << "Tile coor: " << m_map->m_currentCoorTile.x << m_map->m_currentCoorTile.y << std::endl;
    std::cout << std::endl;
    printMovementOptions();
    std::cout << std::endl;
    moveHero(movementDirection::N);

    std::cout << "Tile map: " << std::endl;
    printTileMap();
    std::cout << "Location coor: " << m_map->m_currentCoorLocation.x << m_map->m_currentCoorLocation.y << std::endl;
    std::cout << "Tile coor: " << m_map->m_currentCoorTile.x << m_map->m_currentCoorTile.y << std::endl;
    std::cout << std::endl;
    printMovementOptions();
}

void Game::printMovementOptions(){
    m_map->printMovementOptions();
}

void Game::moveHero(movementDirection direction){
    m_map->moveHero(direction);
}