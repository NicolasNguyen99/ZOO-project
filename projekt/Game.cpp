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
            pickWeapon(new Weapon("Light-Hammer","Hammer", 10));
            pickWeapon(new Weapon("Light-Sword","Sword", 20));
            pickWeapon(new Weapon("Dagger","Dagger", 5));
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

void Game::printStats(){
    m_hero->printStats();
}

void Game::printInventory(){
    m_hero->printInventory();
}

void Game::pickWeapon(Weapon* weapon){
    m_hero->pickWeapon(weapon);
}

void Game::pickArmor(Armor* armor){
    m_hero->pickArmor(armor);
}


void Game::setWeapon(Weapon* weapon){
    m_hero->setWeapon(weapon);
}

void Game::setArmor(Armor* armor){
    m_hero->setArmor(armor);
}

void Game::positionMenu(){
    int action;
    std::cout << "Choose: " << std::endl;
    std::cout << "  1. Print position on map" << std::endl;
    std::cout << "  2. Print position in location" << std::endl;
    std::cout << "  3. Back previous menu" << std::endl;
    std::cin >> action;
    switch(action){
        case 1:
            printLocationMap();
            break;
        case 2:
            printTileMap();
            break;
        case 3:
            gameMenu();
            break;
        default:;
    }
}

void Game::gameMenu(){
    int action;
    std::cout << "You spawn in heaven blalba" << std::endl;
    std::cout << "Welcome to our game" << std::endl;
    std::cout << "  1. Get position" << std::endl;
    std::cout << "  2. Print hero stats" << std::endl;
    std::cout << "  3. Print hero inventory" << std::endl;
    std::cout << "  4. Move to different tile" << std::endl;
    std::cin >> action;
    switch (action){
        case 1:
            positionMenu();
            gameMenu();
            break;
        case 2:
            printStats();
            gameMenu();
            break;
        case 3:
            printInventory();
            gameMenu();
            break;
        case 4:
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

void Game::basicMenu() {
    startMenu();
    gameMenu();
}