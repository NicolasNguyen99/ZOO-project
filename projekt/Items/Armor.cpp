//
// Created by Nicolas Nguyen on 03/12/2020.
//

#include "Armor.h"

Armor::Armor(std::string name):Item(name, "Armor"){
}

void Armor::printItem(){
    Item::printItem();
    std::cout << "Armor bonus: " << m_bonusArmor << "\n";
}