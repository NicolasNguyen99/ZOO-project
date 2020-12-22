//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Game.h"

int Game::getInput(){
    int action;
    std::cin >> action;
    return action;
}

void Game::setUpGame(){
    createHero();
    createMap();
}

void Game::battle(Enemy* enemy){
    std::cout << "You are in battle with "<< enemy->getName() << "\n";
    bool isRunning;
    do{
        isRunning = battleMenu();
    }while(m_hero->getHealth()>0 and enemy->getHealth()>0 and !isRunning);
    if(isRunning){
        std::cout << "Kvo kvo run you little chicken!\n";
    } else if(m_hero->getHealth()>0){
        std::cout << "You dead\n";
        //end game nebo odejit z boje na predchozi policko
    } else if(enemy->getHealth()>0){
        std::cout << "You killed" << enemy->getName() <<"\n";
        //loot enemy
    }
}

bool Game::battleMenu(){
    bool isRunning = false;
    std::cout << "Choose: \n";
    std::cout << "  1. Get battle stats\n";
    std::cout << "  2. Attack\n";
//    std::cout << "  2. Defend\n";
    std::cout << "  3. Drink Potion\n";
    std::cout << "  4. Run away from battle\n";
    switch (getInput()) {
        case 1:
            printHeroStats();

            break;
        case 2:

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
            printInventory();
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

void Game::addItem(Chest* chest){
    if(chest->getWeapon() != nullptr){
        m_hero->pickWeapon(chest->getWeapon());
    } else if(chest->getArmor() != nullptr){
        m_hero->pickArmor(chest->getArmor());
    } else if(chest->getPotion() != nullptr){
        m_hero->pickPotion(chest->getPotion());
    }
    std::cout << "Item has been added to your inventory\n";
}

void Game::itemMenu(){
    Chest* chest = getObjectsInTile().chest;
    std::cout << "Choose: \n";
    std::cout << "  1: Add item to inventory\n";
    std::cout << "  2: Show inventory\n";
    std::cout << "  3: Go back to previous menu\n";
    switch(getInput()){
        case 1:
            addItem(chest);
            removeChest();
            gameMenu();
            break;
        case 2:
            printInventory();
            itemMenu();
            break;
        case 3:
            chestMenu();
            break;
        default:;
    }
}

void Game::chestMenu(){
    objectsInTile objects = getObjectsInTile();
    if(objects.chest != nullptr){
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
    } else {
        std::cout << "You didnt find anything in this tile!\n";
    }
}

void Game::searchTile(){
    objectsInTile objects = getObjectsInTile();
    if(objects.chest != nullptr){
        chestMenu();
    } else {
        std::cout << "You didnt find anything in this tile!\n";
    }
}

void Game::createHero(){
    std::string name, profession;
    std::cout << "Enter hero name: ";
    std::cin >> name;
    std::cout << "Choose hero class: \n";
    std::cout << "  1. Warrior\n";
    std::cout << "  2. Ranger\n";
    std::cout << "  3. Mage\n";
    std::cin >> profession;
    m_hero = new Hero(name, profession);
}

void Game::createMap() {
    m_map = new Map();
}

void Game::getHelp(){
    std::cout << "Help 12312313\n";
}

void Game::startMenu(){
    std::cout << "Welcome to our game\n";
    std::cout << "  1. Start game\n";
    std::cout << "  2. Get help\n";
    std::cout << "  3. Exit game\n";
    switch (getInput()) {
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
            printLocationMap();
            mapMenu();
            break;
        case 2:
            printTileMap();
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
            printHeroStats();
            heroInfoMenu();
            break;
        case 2:
            printInventory();
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
    printMovementOptions();
    std::cout << "Choose movement direction: ";
    std::cin >> action;
    if (action == 'N'){ moveHero(movementDirection::N);}
    else if (action == 'E'){ moveHero(movementDirection::E);}
    else if (action == 'S'){ moveHero(movementDirection::S);}
    else if (action == 'W'){ moveHero(movementDirection::W);}
}

void Game::gameMenu(){
    std::cout << "  1. Get hero review\n";
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

//provolavaci metody do classy Map
void Game::moveHero(movementDirection direction){
    m_map->moveHero(direction);
    if(m_map->getEnemy() != nullptr){
        battle(m_map->getEnemy());
    }
}

void Game::printLocationMap(){
    m_map->printLocationMap();
}

void Game::printTileMap(){
    m_map->printTileMap();
}

void Game::killEnemy(){
    m_map->killEnemy();
}

void Game::removeChest(){
    m_map->removeChest();
}

objectsInTile Game::getObjectsInTile(){
    return m_map->getObjectsInTile();
}

void Game::printMovementOptions(){
    m_map->printMovementOptions();
}

//provolavaci metody do classy Hero
void Game::pickArmor(Armor* armor){
    m_hero->pickArmor(armor);
}

void Game::setWeapon(Weapon* weapon){
    m_hero->setWeapon(weapon);
}

void Game::setArmor(Armor* armor){
    m_hero->setArmor(armor);
}

void Game::printHeroStats(){
    m_hero->printStats();
}

void Game::printInventory(){
    m_hero->printInventory();
}