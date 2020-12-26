//
// Created by Nicolas Nguyen on 26/12/2020.
//

#include "GamePrepare.h"

GamePrepare::GamePrepare(){
    m_game = new Game;
}

void GamePrepare::startMenu(){
    std::cout << "Welcome to our game\n";
    std::cout << "  1. Start game\n";
    std::cout << "  2. Get help\n";
    std::cout << "  3. Exit game\n";
    switch (m_game->getInput()) {
        case 1:
            setUpGame();
            m_game->gameMenu();
            break;
        case 2:
            getHelp();
            startMenu();
            break;
        case 3:
            exit(0);
        default:
            std::cout << "Choose action from menu\n";
            startMenu();
            break;
    }
}

void GamePrepare::getHelp(){
    std::cout << "Help 12312313\n";
}

void GamePrepare::setUpGame(){
    createHero();
    createMap();
}

void GamePrepare::createHero(){
    std::string name, profession;
    std::cout << "Enter hero name: \n";
    std::cin >> name;
    std::cout << "Choose hero class: \n";
    std::cout << "  1. Warrior\n";
    std::cout << "  2. Ranger\n";
    std::cout << "  3. Mage\n";
    std::cin >> profession;
    m_game->setHero(new Hero(name, profession));
}

void GamePrepare::createMap(){
    m_game->setMap(new Map());
}