//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Game.h"

Game::Game(){
    basicMenu();
}

void Game::printLocationMap(){
    m_map->printLocationMap();
}

void Game::printTileMap(){
    std::cout << "Tile map: " << std::endl;
    m_map->printTileMap();
}

void Game::setUpGame(){
    createHero();
    createMap();
}

void Game::createHero(){
    std::string name, profession;
    std::cout << "Enter hero name: ";
    std::cin >> name;
    std::cout << "Choose hero class: " << std::endl;
    std::cout << "  1. Warrior" << std::endl;;
    std::cout << "  2. Ranger" << std::endl;;
    std::cout << "  3. Mage" << std::endl;;
    std::cin >> profession;

    m_hero = new Hero(name, profession);
}

void Game::createMap() {
    m_map = new Map();
}

void Game::printMovementOptions(){
    m_map->printMovementOptions();
}

void Game::moveHero(movementDirection direction){
    m_map->moveHero(direction);
    m_map->getEnemy();
}

void Game::getHelp(){
    std::cout << "Help 12312313" << std::endl;
}

void Game::startMenu(){
    int action;
    std::cout << "Welcome to our game" << std::endl;
    std::cout << "  1. Start game" << std::endl;
    std::cout << "  2. Get help" << std::endl;
    std::cout << "  3. Exit game" << std::endl;
    std::cin >> action;
    switch (action) {
        case 1:
            setUpGame();
            break;
        case 2:
            getHelp();
            basicMenu();
            break;
        case 3:
            exit(0);
        default:;
    }
}

void Game::gameMenu(){
    int action;
    std::cout << "You spawn in heaven blalba" << std::endl;
    std::cout << "Welcome to our game" << std::endl;
    std::cout << "  1. Print map" << std::endl;
    std::cout << "  2. Print location" << std::endl;
    std::cout << "  3. Move to different tile" << std::endl;
    std::cin >> action;
    switch (action){
        case 1:
            printLocationMap();
            gameMenu();
            break;
        case 2:
            printTileMap();
            gameMenu();
            break;
        case 3:
            printMovementOptions();
            std::cout << "Choose movement direction: ";
            std::cin >> action;
            if (action == 'N'){ moveHero(movementDirection::N);}
            else if (action == 'E'){ moveHero(movementDirection::E);}
            else if (action == 'S'){ moveHero(movementDirection::S);}
            else if (action == 'W'){ moveHero(movementDirection::W);}
            gameMenu();
            break;
        default:;
    }
}

void Game::basicMenu(){
    startMenu();
    gameMenu();


//    do {
//        std::cout << "#######################################################################" << std::endl;
//        std::cout << "Tile map: " << std::endl;
//        printTileMap();
//        std::cout << "Location coor: " << m_map->getCurrentCoorLocation().x << m_map->getCurrentCoorLocation().y << std::endl;
//        std::cout << "Tile coor: " << m_map->getTilepositionCoor().x << m_map->getTilepositionCoor().y << std::endl;
//        printMovementOptions();
//        std::cout << "Enter movement direction: " << std::endl;
//        std::cin >> action;
//        if (action == 'N') { moveHero(movementDirection::N); }
//        if (action == 'E') { moveHero(movementDirection::E); }
//        if (action == 'S') { moveHero(movementDirection::S); }
//        if (action == 'W') { moveHero(movementDirection::W); }
//        std::cout << "#######################################################################" << std::endl;
//    } while (action != 'K');
}