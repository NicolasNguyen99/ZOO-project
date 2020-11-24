//
// Created by Nicolas Nguyen on 24/11/2020.
//

#include "Game.h"

int Game::getInput(){
    int action;
    std::cin >> action;
    return action;
}

void Game::printChooseDialog(){
    std::cout << "Choose nuber of action" << std::endl;
}

void Game::setGame(){
    std::cout << "Choose size of your map" << std::endl;
    std::cout << "  1.  Small" << std::endl;
    std::cout << "  2.  Medium" << std::endl;
    std::cout << "  3.  Large" << std::endl;
    int size;
    std::cin >> size;
    if(size == 1){
        m_map = new Map(mapSize::Small);
    } else if(size == 2){
        m_map = new Map(mapSize::Medium);
    } else if(size == 3){
        m_map = new Map(mapSize::Large);
    }
    m_hero = nullptr;
}

void Game::printMainMenu(){
    printChooseDialog();
    std::cout << "1. Start game" << std::endl;
    std::cout << "2. Print help" << std::endl;
    std::cout << "3. Exit game" << std::endl;
}

void Game::printHelp(){
    std::cout << "Napoveda do hry" << std::endl;
}

void Game::communication(){
    std::cout << "Vitej ve hre" << std::endl;
    printMainMenu();
    switch(getInput()){
        case 1:
            setGame();
            break;
        case 2:
            printHelp();
            break;
        case 3:
            exit(0);
        default:
            break;
    }
}

Game::Game(){
    communication();
}

void Game::moveHero(movementDirection direction){
    m_map->moveHero(direction);
}

void Game::printMap(){
    m_map->printMap();
}

void Game::printMovementOptions(){
   m_map->printMovementOptions();
}