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
    void gameMenu();
    void movementMenu();
    void mapMenu();
    void heroInfoMenu();
    void inventoryActionMenu();
    void actionMenu();
    void chestMenu();
    void itemMenu();
    void setUpGame();
    void getHelp();
    void printLocationMap();
    void printTileMap();
    void printMovementOptions();
    void moveHero(movementDirection direction);
    void printStats();
    void printInventory();
    objectsInTile getObjectsInTile();
    void setWeapon(Weapon* weapon);
    void setArmor(Armor* armor);
    void pickWeapon(Weapon* weapon);
    void removeChest();
    void pickArmor(Armor* armor);
    void searchTile();
    void printChestItem(Chest* chest);
    void addItem(Chest* chest);

public:
    Game(){};
    void startMenu();
};


#endif //PROJEKT_GAME_H
