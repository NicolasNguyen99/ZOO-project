//
// Created by Nicolas Nguyen on 03/12/2020.
//

#include "Armor.h"

Armor::Armor(std::string name, int bonusArmor):Item(name, "Armor"){
    m_bonusArmor = bonusArmor;
}

void Armor::printItem(){
    Item::printItem();
    std::cout << "Armor bonus: " << m_bonusArmor << "\n";
}

void Armor::reduceArmor(int damage){
    m_bonusArmor -= damage;
}

int Armor::getBonusArmor(){
    return m_bonusArmor;
}