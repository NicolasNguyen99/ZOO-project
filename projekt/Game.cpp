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
    createHero();
    createMap();
}

void Game::createHero(){
    m_hero = new Hero("Nicolas", 110, 10);
}

void Game::createMap() {
    m_map = new Map();

    printLocationMap();
    std::cout << std::endl;

    char vstup;
    do {
        std::cout << "#######################################################################" << std::endl;
        std::cout << "Tile map: " << std::endl;
        printTileMap();
        std::cout << "Location coor: " << m_map->getCurrentCoorLocation().x << m_map->getCurrentCoorLocation().y << std::endl;
        std::cout << "Tile coor: " << m_map->getTilepositionCoor().x << m_map->getTilepositionCoor().y << std::endl;
        printMovementOptions();
        std::cout << "Enter movement direction: " << std::endl;
        std::cin >> vstup;
        if (vstup == 'N') { moveHero(movementDirection::N); }
        if (vstup == 'E') { moveHero(movementDirection::E); }
        if (vstup == 'S') { moveHero(movementDirection::S); }
        if (vstup == 'W') { moveHero(movementDirection::W); }
        std::cout << "#######################################################################" << std::endl;
    } while (vstup != 'K');
}

void Game::printMovementOptions(){
    m_map->printMovementOptions();
}

void Game::moveHero(movementDirection direction){
    m_map->moveHero(direction);
}