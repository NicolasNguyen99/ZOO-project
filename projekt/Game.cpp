#include "Game.h"
Game::Game(){
    m_hero = nullptr;
    m_map = nullptr;
}

int Game::getInput(){
    int action;
    std::cin >> action;
    return action;
}

void Game::battle(Enemy* enemy){
    std::cout << "You are in battle with "<< enemy->getName() << "\n";
    bool isRunning;
    do{
        isRunning = battleMenu(enemy);
    }while(m_hero->getHealth()>0 and enemy->getHealth()>0 and !isRunning);
    if(isRunning){
        m_hero->takeDamage(enemy->getStrength());
        std::cout << "Kvo kvo run you little chicken!\n";
        //otoceni pohybu
        int num = -(int(m_map->getPreviousMovement()));
        m_map->moveHero(movementDirection(num));
    } else if(m_hero->getHealth()<=0){
        std::cout << "You died\n";
        exit(0);
    } else if(enemy->getHealth()<=0){
        std::cout << "You have killed " << enemy->getName() <<"\n";
        m_hero->addXp(enemy->getXpReward());
        m_map->killEnemy();
    }
}

void Game::attack(Enemy* enemy){
    enemy->takeDamage(m_hero->getStrength());
    m_hero->takeDamage(enemy->getStrength());
}

void Game::printBattleStats(){
    std::cout << "Battle stats: \n";
    m_hero->printStats();
    m_map->printEnemyStats();
}

bool Game::battleMenu(Enemy* enemy){
    bool isRunning = false;
    std::cout << "Choose: \n";
    std::cout << "  1. Get battle stats\n";
    std::cout << "  2. Attack\n";
//    std::cout << "  2. Defend\n";
    std::cout << "  3. Drink Potion\n";
    std::cout << "  4. Run away from battle\n";
    switch (getInput()) {
        case 1:
            printBattleStats();
            break;
        case 2:
            attack(enemy);
            printBattleStats();
            break;
        case 3:

            break;
        case 4:
            isRunning = true;
            break;
        default:;
    }
    return isRunning;
}

void Game::weaponChangeMenu(){
    std::cout << "Equiped weapon: \n";
    m_hero->printEquipedWeapon();
    std::cout << "Weapons in your inventory: \n";
    m_hero->printWeapons();
    std::cout << "Choose index of weapon: \n";
    if(m_hero->equipWeapon(getInput()) == 0){
        std::cout << "Weapon is equipped\n";
    } else {
        std::cout << "Weapon on wasnt found\n";
        weaponChangeMenu();
    }
    inventoryMenu();
}

void Game::itemChangeMenu(){
    std::cout << "Choose: \n";
    std::cout << "  1. Change equipped weapon\n";
    std::cout << "  2. Change equipped armor\n";
    std::cout << "  3. Back to previous menu\n";
    switch (getInput()) {
        case 1:
            weaponChangeMenu();
            break;
        case 2:

            break;
        case 3:
            //    swapArmor();//
            break;
        default:;
    }
}

void Game::inventoryMenu() {
    std::cout << "Choose: \n";
    std::cout << "  1. Show inventory\n";
    std::cout << "  2. Change equipment\n";
    std::cout << "  3. Drop item\n";
    std::cout << "  4. Back to previous menu\n";
    switch (getInput()) {
        case 1:
            m_hero->printInventory();
            inventoryMenu();
            break;
        case 2:
            itemChangeMenu();
            break;
        case 3:
            //    swapArmor();//
            break;
        case 4:
            gameMenu();
            break;
        default:;
    }
}

void Game::actionMenu(){
    m_map->printTileMap();
    std::cout << "Choose: \n";
    std::cout << "  1. Travel\n";
    std::cout << "  2. Show inventory menu\n";
    std::cout << "  3. Search tile\n";
    std::cout << "  4. Back to previous menu\n";
    switch (getInput()) {
        case 1:
            movementMenu();
            actionMenu();
            break;
        case 2:
            inventoryMenu();
            break;
        case 3:
            searchTile();
            break;
        case 4:
            gameMenu();
            break;
        default:;
    }
}

void Game::itemMenu(){
    Chest* chest = m_map->getObjectsInTile().chest;
    std::cout << "Choose: \n";
    std::cout << "  1: Add item to inventory\n";
    std::cout << "  2: Show inventory\n";
    std::cout << "  3: Go back to previous menu\n";
    switch(getInput()){
        case 1:
            m_hero->addItem(chest);
            m_map->removeChest();;
            actionMenu();
            break;
        case 2:
            m_hero->printInventory();
            itemMenu();
            break;
        case 3:
            actionMenu();
            break;
        default:;
    }
}

void Game::chestMenu(){
    objectsInTile objects = m_map->getObjectsInTile();
    std::cout << "You have found a chest!\n";
    std::cout << "Choose: \n";
    std::cout << "  1. Open chest \n";
    std::cout << "  2. Leave chest \n";
    switch(getInput()){
        case 1:
            printChestItem(objects.chest);
            itemMenu();
            break;
        case 2:
            actionMenu();
            break;
        default:;
    }
}

void Game::searchTile(){
    objectsInTile objects = m_map->getObjectsInTile();
    if(objects.chest != nullptr){
        chestMenu();
    } else {
        std::cout << "You didnt find anything in this tile!\n";
        actionMenu();
    }
}

void Game::printChestItem(Chest* chest){
    if(chest->getWeapon() != nullptr){
        Weapon* weapon = chest->getWeapon();
        std::cout << "You have found a weapon!\n";
        weapon->printItem();
    } else if(chest->getArmor() != nullptr){
        Armor* armor = chest->getArmor();
        std::cout << "You have found a armor!\n";
        armor->printItem();
    } else if(chest->getPotion() != nullptr){
        Potion* potion = chest->getPotion();
        std::cout << "You have found a potion!\n";
        potion->printItem();
    }
}

void Game::mapMenu(){
    std::cout << "Choose: \n";
    std::cout << "  1. Show map\n";
    std::cout << "  2. Show your position\n";
    std::cout << "  3. Back previous menu\n";
    switch(getInput()){
        case 1:
            m_map->printLocationMap();;
            mapMenu();
            break;
        case 2:
            m_map->printTileMap();
            mapMenu();
            break;
        case 3:
            gameMenu();
            break;
        default:;
    }
}

void Game::heroInfoMenu(){
    std::cout << "Choose: \n";
    std::cout << "  1. Print hero stats\n";
    std::cout << "  2. Print hero inventory\n";
    std::cout << "  3. Back previous menu\n";
    switch(getInput()){
        case 1:
            m_hero->printStats();
            heroInfoMenu();
            break;
        case 2:
            m_hero->printInventory();
            heroInfoMenu();
            break;
        case 3:
            gameMenu();
            break;
        default:;
    }
}

void Game::movementMenu(){
    char action;
    m_map->printMovementOptions();
    std::cout << "Choose movement direction: ";
    std::cin >> action;
    if (action == 'N'){ moveHero(movementDirection::N);}
    else if (action == 'E'){ moveHero(movementDirection::E);}
    else if (action == 'S'){ moveHero(movementDirection::S);}
    else if (action == 'W'){ moveHero(movementDirection::W);}
}

void Game::gameMenu(){
    std::cout << "  1. Hero review\n";
    std::cout << "  2. Open map\n";
    std::cout << "  3. Open action menu\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    switch (getInput()){
        case 1:
            heroInfoMenu();
            break;
        case 2:
            mapMenu();
            break;
        case 3:
            actionMenu();
            break;
        default:;
    }
}

void Game::moveHero(movementDirection direction){
    m_map->moveHero(direction);
    if(m_map->getEnemy() != nullptr){
        battle(m_map->getEnemy());
    }
}

void Game::setHero(Hero* hero){
    m_hero = hero;
}

void Game::setMap(Map* map){
    m_map = map;
}