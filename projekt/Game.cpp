//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Game.h"

Game::Game(){
    startMenu();
}

void Game::printLocationMap(){
    m_map->printLocationMap();
}

void Game::printTileMap(){
    std::cout << "Tile map: \n";
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
    std::cout << "Choose hero class: \n";
    std::cout << "  1. Warrior\n";;
    std::cout << "  2. Ranger\n";;
    std::cout << "  3. Mage\n";;
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
    std::cout << "Help 12312313\n";
}

void Game::startMenu(){
    int action;
    std::cout << "Welcome to our game\n";
    std::cout << "  1. Start game\n";
    std::cout << "  2. Get help\n";
    std::cout << "  3. Exit game\n";
    std::cin >> action;
    switch (action) {
        case 1:
            setUpGame();
            gameMenu();
            break;
        case 2:
            getHelp();
            startMenu();
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

void Game::getObjectsInTile(){
    objectsInTile objects = m_map->getObjectsInTile();
    std::cout << objects.chest << std::endl;
    if(objects.enemy == nullptr){
        std::cout << "Na tomto policku neni enemy\n";
    } else {
        std::cout << objects.enemy->getName() << std::endl;
    }
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
    std::cout << "Choose: \n";
    std::cout << "  1. Print position on map\n";
    std::cout << "  2. Print position in location\n";
    std::cout << "  3. Back previous menu\n";
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

void Game::heroInfoMenu(){
    int action;
    std::cout << "Choose: \n";
    std::cout << "  1. Print hero stats\n";
    std::cout << "  2. Print hero inventory\n";
    std::cout << "  3. Back previous menu\n";
    std::cin >> action;
    switch(action){
        case 1:
            printStats();
            break;
        case 2:
            printInventory();
            break;
        case 3:
            gameMenu();
            break;
        default:;
    }
}

void Game::movementMenu(){
    char action;
    printMovementOptions();
    std::cout << "Choose movement direction: ";
    std::cin >> action;
    if (action == 'N'){ moveHero(movementDirection::N);}
    else if (action == 'E'){ moveHero(movementDirection::E);}
    else if (action == 'S'){ moveHero(movementDirection::S);}
    else if (action == 'W'){ moveHero(movementDirection::W);}
}

void Game::gameMenu(){
    int action;
    std::cout << "You spawn in heaven blalba\n";
    std::cout << "Welcome to our game\n";
    std::cout << "  1. Get position\n";
    std::cout << "  2. Get information of your hero\n";
    std::cout << "  3. Move to different tile\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> action;
    switch (action){
        case 1:
            positionMenu();
            gameMenu();
            break;
        case 2:
            heroInfoMenu();
            break;
        case 3:
            movementMenu();
            gameMenu();
            break;
        default:;
    }
}