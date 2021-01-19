//
// Created by Nicolas Nguyen on 10/12/2020.
//

#include "Inventory.h"

Inventory::Inventory(){
    for(auto &m_weapon:m_weapons){
        m_weapon = nullptr;
    }
    for(auto &m_armor:m_armors){
        m_armor = nullptr;
    }
    for(auto &m_potion:m_potions){
        m_potion = nullptr;
    }
    m_weapons.at(0) = new Weapon("Weapon1", "Light weapon", 20);
    m_weapons.at(1) = new Weapon("Weapon2", "Light weapon", 20);
    m_weapons.at(2) = new Weapon("Weapon3", "Light weapon", 20);
    m_armors.at(0) = new Armor("Light armor", 20);
    m_armors.at(1) = new Armor("Heavy armor2", 20);
    m_potions.at(0) = new Potion("Potion", "Medium potion", 30);
    m_potions.at(1) = new Potion("Potion2", "Medium potion", 30);
}

char Inventory::convertCharToSmall(char letter){
    int difference = int('a') - int('A');
    if(letter >= 'A' and letter <= 'Z'){
        letter += difference;
    }
    return letter;
}

int Inventory::getInput(){
    int action;
    std::cin >> action;
    return action;
}

void Inventory::dropItemMenu(){
    std::cout << "Choose category by first char and index of item that you want to drop: \n";
    printInventory();
    char category;
    std::cin >> category;
    category = convertCharToSmall(category);
    int index  = getInput();

    if(category == 'w'){
        if(getWeapon(index) != nullptr){
            discardItem<>(m_weapons, index);
        }
    } else if(category == 'a'){
        if(getArmor(index) != nullptr){
            discardItem<>(m_armors, index);
        }
    } else if(category == 'p'){
        if(getPotion(index) != nullptr){
            discardItem<>(m_potions, index);
        }
    } else {
        std::cout << "You have entered wrong category, try again.\n";
        dropItemMenu();
    }
}

void Inventory::discardPotion(int index){
    discardItem(m_potions, index);
}

Weapon* Inventory::getWeapon(int index){
    Weapon* weapon;
    if(index > 0 and index <= m_weapons.size()){
        weapon = m_weapons.at(index-1);
    } else {
        weapon = nullptr;
    }
    return weapon;
}

Armor* Inventory::getArmor(int index){
    Armor* armor;
    if(index > 0 and index <= m_armors.size()){
        armor = m_armors.at(index-1);
    } else {
        armor = nullptr;
    }
    return armor;
}

Potion* Inventory::getPotion(int index){
    Potion* potion;
    if(index > 0 and index <= m_potions.size()){
        potion = m_potions.at(index-1);
    } else {
        potion = nullptr;
    }
    return potion;
}

void Inventory::addWeapon(Weapon* weapon){
    addItem<>(m_weapons, weapon);
}

void Inventory::addArmor(Armor* armor){
    addItem<>(m_armors, armor);
}

void Inventory::addPotion(Potion* potion){
    addItem<>(m_potions, potion);
}

void Inventory::printWeapons(){
    std::cout << "Weapons: " << std::endl;
    printItems<>(m_weapons);
}

void Inventory::printArmors(){
    std::cout << "Armors: " << std::endl;
    printItems<>(m_armors);
}

void Inventory::printPotions(){
    std::cout << "Potions: " << std::endl;
    printItems<>(m_potions);
}

void Inventory::printInventory(){
    std::cout << "Inventory: \n";
    std::cout << "--------------------------------" << std::endl;
    printWeapons();
    std::cout << "--------------------------------" << std::endl;
    printArmors();
    std::cout << "--------------------------------" << std::endl;
    printPotions();
    std::cout << "--------------------------------" << std::endl;
}

void Inventory::suspendWeapon(int index){
    suspendItem<>(m_weapons, index);
}

void Inventory::suspendArmor(int index){
    suspendItem<>(m_armors, index);
}

ArrayOfPotions Inventory::getPotions(){
    return m_potions;
}

ArrayOfWeapons Inventory::getWeapons(){
    return m_weapons;
}

ArrayOfArmors Inventory::getArmors(){
    return m_armors;
}