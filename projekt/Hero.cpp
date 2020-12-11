//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Hero.h"

Hero::Hero(std::string name, std::string profession):Character(name){
    m_abilityPower = 0;
    m_health = 100;
    m_strength = 10;
    m_inventory = new Inventory();
}

int Hero::getAbilityPower(){
    return m_abilityPower;
}

void Hero::printStats(){
    std::cout << m_name + " stats: " << std::endl;
    std::cout << "  -health: " << m_health << std::endl;
    std::cout << "  -strength: " << m_strength << std::endl;
    std::cout << "  -ability power: " << m_abilityPower << std::endl;
}

void Hero::printInventory(){
    m_inventory->printInventory();
}

void Hero::setWeapon(Weapon* weapon){
    m_weapon = weapon;
}

void Hero::setArmor(Armor* armor){
    m_armor = armor;
}

void Hero::pickWeapon(Weapon* weapon){
    m_inventory->setWeapon(weapon);
}

void Hero::pickArmor(Armor* armor){
    m_inventory->setArmor(armor);
}
