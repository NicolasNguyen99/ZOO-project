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
    m_armor = nullptr;
//    m_armor = new Armor("Light armor", 10);
    m_haveKey = false;
}

int Hero::getInput(){
    int action;
    std::cin >> action;
    return action;
}

int Hero::getAbilityPower(){
    return m_abilityPower;
}

void Hero::weaponChangeMenu(){
    if(!m_inventory->checkEmptyInv(m_inventory->getWeapons())){
        printEquipedWeapon();
        printWeapons();
        std::cout << "Choose index of weapon, that you want to equip: \n";
        int index = getInput();
        if (equipWeapon(index) == 0) {
            std::cout << "Weapon is equipped\n";
        } else {
            std::cout << "Weapon on " << index << ". index wasnt found\n";
            weaponChangeMenu();
        }
    } else {
        std::cout << "You do not have any weapons in your inventory\n";
    }
}

void Hero::armorChangeMenu(){
    if(!m_inventory->checkEmptyInv(m_inventory->getArmors())) {
        printEquipedArmor();
        printArmors();
        std::cout << "Choose index of armor, that you want to equip: \n";
        int index = getInput();
        if (equipArmor(index) == 0) {
            std::cout << "Armor is equipped\n";
        } else {
            std::cout << "Armor on " << index << ". index wasnt found\n";
            armorChangeMenu();
        }
    } else {
        std::cout << "You do not have any armors in your inventory\n";
    }
}

void Hero::drinkPotionMenu(){
    if(!m_inventory->checkEmptyInv(m_inventory->getPotions())){
        std::cout << "Choose index of potion that you want to drink: \n";
        m_inventory->printPotions();
        int index = getInput();
        if (drinkPotion(index) == 0) {
            std::cout << "You drank a potion\n";
        } else {
            std::cout << "Potion on " << index << ". index wasnt found\n";
            drinkPotionMenu();
        }
    } else {
        std::cout << "You do not have any potions in your inventory\n";
    }
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
    if((m_currentXp + xp) >= m_maxXp){
        m_currentXp += xp;
        levelCalc();
    }
}

void Hero::printEquipedWeapon(){
    std::cout << "\nEquipped weapon: \n";
    printEquipedItem(m_weapon);
    std::cout << "\n";
}

void Hero::printEquipedArmor(){
    std::cout << "\nEquipped armor: \n";
    printEquipedItem(m_armor);
    std::cout << "\n";
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
        m_inventory->suspendWeapon(index);
    } else {
        endNum = 1;
    }
    return endNum;
}

int Hero::equipArmor(int index){
    int endNum;
    Armor* selectedArmor = m_inventory->getArmor(index);
    if(selectedArmor != nullptr){
        if(m_armor != nullptr){
            m_inventory->addArmor(m_armor);
        }
        setArmor(selectedArmor);
        endNum = 0;
        m_inventory->suspendArmor(index);
    } else {
        endNum = 1;
    }
    return endNum;
}

int Hero::drinkPotion(int index){
    int endNum;
    Potion* selectedPotion = m_inventory->getPotion(index);
    if(selectedPotion != nullptr){
        heal(selectedPotion->getHealAmount());
        m_inventory->discardPotion(index);
        endNum = 0;
    } else {
        endNum = 1;
    }
    return endNum;
}

void Hero::heal(int amount){
    if(m_currentHealth + amount >= m_maxHealth){
        m_currentHealth = m_maxHealth;
    } else {
        m_currentHealth += amount;
    }
}

void Hero::printStats(){
    std::cout << m_name + " stats: \n";
    std::cout << " -Level: " << m_level << "\n";
    std::cout << " -Xp: " << m_currentXp << "/" << m_maxXp << "\n";
    std::cout << " -Health: " << m_currentHealth << "/" << m_maxHealth<< "\n";
    std::cout << " -Strength: " << m_strength << "\n";
    std::cout << " -Ability power: " << m_abilityPower << "\n";
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
    bool didLevelUp = false;
    while((m_currentXp - m_maxXp) >= 0){
        m_currentXp -= m_maxXp;
        m_level++;
        levelUp();
        didLevelUp = true;
    }
    if(didLevelUp){
        std::cout << "Level up!\n";
    }
}

void Hero::levelUp(){
    m_maxHealth += 2*m_level;
    m_currentHealth += 2*m_level;
    m_maxXp += m_level * 5;
}

void Hero::dropItemMenu(){
    m_inventory->dropItemMenu();
}
