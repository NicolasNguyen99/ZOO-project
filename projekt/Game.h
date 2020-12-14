//
// Created by Nicolas Nguyen on 02/12/2020.
//

#ifndef PROJEKT_GAME_H
#define PROJEKT_GAME_H
#include "Map.h"
#include "Hero.h"

class Game {
    Hero* m_hero;
    Map* m_map;
    void createHero();
    void createMap();

    void startMenu();
    void gameMenu();
public:
    Game();
    void printLocationMap();
    void printTileMap();
    void printMovementOptions();
    void moveHero(movementDirection direction);
    void setUpGame();
    void printStats();
    void printInventory();
    void getHelp();
    objectsInTile getObjectsInTile();
    void setWeapon(Weapon* weapon);
    void setArmor(Armor* armor);
    void pickWeapon(Weapon* weapon);
    void pickArmor(Armor* armor);
    void movementMenu();
    void mapMenu();
    void heroInfoMenu();
    void inventoryActionMenu();
    void actionMenu();
    void printChestItem(Chest* chest);
};


#endif //PROJEKT_GAME_H
