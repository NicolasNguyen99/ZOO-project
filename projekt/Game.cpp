//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Game.h"

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

void Game::inventoryActionMenu() {
    int action;
    std::cout << "Choose: \n";
    std::cout << "  2. Show inventory actions\n";
    std::cout << "  3. Search tile\n";
    std::cout << "  4. Back to previous menu\n";
    std::cin >> action;
    switch (action) {
        case 1:
            //   manageInventory();//
            break;
        case 2:
            //    swapWeapon();//
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
    int action;
    std::cout << "Choose: \n";
    std::cout << "  1. Travel\n";
    std::cout << "  2. Show inventory actions\n";
    std::cout << "  3. Search tile\n";
    std::cout << "  4. Back to previous menu\n";
    std::cin >> action;
    switch (action) {
        case 1:
            movementMenu();
            actionMenu();
            break;
        case 2:
            inventoryActionMenu();
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

void Game::removeChest(){
    m_map->removeChest();
}

void Game::itemMenu(){
    Chest* chest = getObjectsInTile().chest;
    std::cout << "Choose: \n";
    std::cout << "  1: Add item to inventory\n";
    std::cout << "  2: Show inventory\n";
    std::cout << "  3: Go back to previous menu\n";
    int action;
    std::cin >> action;
    switch(action){
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
        int action;
        std::cin >> action;
        switch(action){
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

objectsInTile Game::getObjectsInTile(){
    return m_map->getObjectsInTile();
}

void Game::printChestItem(Chest* chest){
    if(chest->getWeapon() != nullptr){
        Weapon* weapon = chest->getWeapon();
        std::cout << "You have found a weapon!\n";
        std::cout << "  Name: " + weapon->getName() + "\n";
        std::cout << "  Type: " + weapon->getType() + "\n";
        std::cout << "  Strength: " << weapon->getBonusStrength() << "\n";
    } else if(chest->getArmor() != nullptr){
        Armor* armor = chest->getArmor();
        std::cout << "You have found a armor!\n";
        std::cout << "  Name: " + armor->getName() + "\n";
        std::cout << "  Type: " + armor->getType() + "\n";
        std::cout << "  Armor: " << armor->getBonusArmor<< "\n";
    } else if(chest->getPotion() != nullptr){
        Potion* potion = chest->getPotion();
        std::cout << "You have found a potion!\n";
        std::cout << "  Name: " + potion->getName() + "\n";
        std::cout << "  Type: " + potion->getType() + "\n";
        std::cout << "  Heal amount: " << potion->getHealAmount()<< "\n";
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

void Game::mapMenu(){
    int action;
    std::cout << "Choose: \n";
    std::cout << "  1. Show map\n";
    std::cout << "  2. Show your position\n";
    std::cout << "  3. Back previous menu\n";
    std::cin >> action;
    switch(action){
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
    int action;
    std::cout << "Choose: \n";
    std::cout << "  1. Print hero stats\n";
    std::cout << "  2. Print hero inventory\n";
    std::cout << "  3. Back previous menu\n";
    std::cin >> action;
    switch(action){
        case 1:
            printStats();
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
    int action;
    std::cout << "  1. Get hero review\n";
    std::cout << "  2. Open map\n";
    std::cout << "  3. Open action menu\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> action;
    switch (action){
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