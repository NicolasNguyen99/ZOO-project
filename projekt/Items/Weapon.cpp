//
// Created by Nicolas Nguyen on 03/12/2020.
//

#include "Weapon.h"


Weapon::Weapon(std::string name, std::string type, int bonusStrength):Item(name, type){
    m_bonusStrength = bonusStrength;
}

int Weapon::getBonusStrength(){
    return m_bonusStrength;
}

void Weapon::printItem(){
    Item::printItem();
    std::cout << " -Strength bonus: " << m_bonusStrength << "\n";
}