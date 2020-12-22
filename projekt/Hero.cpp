//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Hero.h"

Hero::Hero(std::string name, std::string profession):Character(name, 100, 20){
    m_level = 1;
    m_currentXp = 0;
    m_maxXp = 25;
    m_abilityPower = 0;
    m_strength = 10;
    m_inventory = new Inventory();
    m_weapon = nullptr;
    m_armor = nullptr;
    m_haveKey = false;
}

int Hero::getAbilityPower(){
    return m_abilityPower;
}

void Hero::printEquipedWeapon(){
    if(m_weapon != nullptr){
        m_weapon->printItem();
    } else {
        std::cout << "You dont have equipped any weapon\n";
    }

}

void Hero::printEquipedArmor(){
    m_armor->printItem();
}

void Hero::printWeapons(){
    m_inventory->printWeapons();
}

void Hero::printArmors(){
    m_inventory->printArmors();
}

void Hero::printStats(){
    std::cout << m_name + " stats: " << std::endl;
    std::cout << "  -level: " << m_level << std::endl;
    std::cout << "  -xp: " << m_currentXp << "/" << m_maxXp << std::endl;
    std::cout << "  -health: " << m_currentHealth << "/" << m_maxHealth<< std::endl;
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

void Hero::pickPotion(Potion* potion){
    m_inventory->setPotion(potion);
}

void Hero::levelCalc(){
    m_currentXp = m_currentXp - m_maxXp;
    m_level++;
    m_maxXp += m_level * 5;
}

void Hero::levelUp(){
    m_maxHealth += 2*m_level;
    m_currentHealth += 2*m_level;
}
