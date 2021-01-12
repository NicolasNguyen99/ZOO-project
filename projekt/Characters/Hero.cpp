//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Hero.h"

Hero::Hero(std::string name, std::string profession):Character(name, 100, 20){
    m_level = 1;
    m_currentXp = 0;
    m_maxXp = 20;
    m_abilityPower = 0;
    m_strength = 25;
    m_inventory = new Inventory();
    m_weapon = nullptr;
    m_armor = new Armor("Light armor", 10);
    m_haveKey = false;
}

int Hero::getAbilityPower(){
    return m_abilityPower;
}

void Hero::takeDamage(int damage){
    if(m_armor != nullptr){
        if(m_armor->getBonusArmor()-damage <= 0){
            std::cout << "Enemy attack has destroyed your armor! \n";
            m_currentHealth += m_armor->getBonusArmor()-damage;
            delete m_armor;
            m_armor = nullptr;
        } else {
            m_armor->reduceArmor(damage);
        }
    } else {
        m_currentHealth -= damage;
    }
}

void Hero::addXp(int xp){
    if(m_currentXp+xp >= m_maxXp){
        levelCalc();
        levelUp();
        std::cout << "Level Up!\n";
    } else {
        m_currentXp += xp;
    }
}

void Hero::printEquipedWeapon(){
    if(m_weapon != nullptr){
        std::cout << "Equipped weapon: \n";
        m_weapon->printItem();
    } else {
        std::cout << " -No equipped weapon\n";
    }
}

void Hero::printEquipedArmor(){
    if(m_armor != nullptr){
        std::cout << "Equipped armor: \n";
        m_armor->printItem();
    } else {
        std::cout << " -No equipped armor\n";
    }
}

void Hero::printWeapons(){
    m_inventory->printWeapons();
}

void Hero::printArmors(){
    m_inventory->printArmors();
}

int Hero::equipWeapon(int index){
    int endNum;
    Weapon* selectedWeapon = m_inventory->getWeapon(index);
    if(selectedWeapon != nullptr){
        if(m_weapon != nullptr){
            m_inventory->addWeapon(m_weapon);
        }
        setWeapon(selectedWeapon);
        endNum = 0;
        m_inventory->removeWeapon(index);
    } else {
        endNum = 1;
    }
    return endNum;
}

void Hero::printStats(){
    std::cout << m_name + " stats: \n";
    std::cout << " -Level: " << m_level << "\n";
    std::cout << " -Xp: " << m_currentXp << "/" << m_maxXp << "\n";
    std::cout << " -Health: " << m_currentHealth << "/" << m_maxHealth<< "\n";
    std::cout << " -Strength: " << m_strength << "\n";
    std::cout << " -Ability power: " << m_abilityPower << "\n";
    std::cout << "\n";
    printEquipedWeapon();
    printEquipedArmor();
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

void Hero::addItem(Chest* chest){
    if(chest->getWeapon() != nullptr){
        m_inventory->addWeapon(chest->getWeapon());
    } else if(chest->getArmor() != nullptr){
        m_inventory->addArmor(chest->getArmor());
    } else if(chest->getPotion() != nullptr){
        m_inventory->addPotion(chest->getPotion());
    }
    std::cout << "Item has been added to your inventory\n";
}

void Hero::levelCalc(){
    m_currentXp -= m_maxXp;
    m_level++;
    m_maxXp += m_level * 5;
}

void Hero::levelUp(){
    m_maxHealth += 2*m_level;
    m_currentHealth += 2*m_level;
}
