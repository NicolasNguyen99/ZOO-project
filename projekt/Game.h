//
// Created by Nicolas Nguyen on 02/12/2020.
//

#ifndef PROJEKT_GAME_H
#define PROJEKT_GAME_H
#include "Map.h"
#include "Characters/Hero.h"

class Game {
    Hero* m_hero;
    Map* m_map;
    void movementMenu();
    void mapMenu();
    void heroInfoMenu();
    void inventoryMenu();
    void actionMenu();
    void chestMenu();
    void itemMenu();
    void moveHero(movementDirection direction);
    void itemChangeMenu();
    void searchTile();
    void printChestItem(Chest* chest);
    void addItem(Chest* chest);
    void attack(Enemy* enemy);
    void battle(Enemy* enemy);
    bool battleMenu(Enemy* enemy);
    void weaponChangeMenu();
    void printBattleStats();

public:
    Game();
    void gameMenu();
    void setHero(Hero* hero);
    void setMap(Map* map);
    int getInput();
};


#endif //PROJEKT_GAME_H
