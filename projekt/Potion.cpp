//
// Created by Nicolas Nguyen on 03/12/2020.
//

#include "Potion.h"

Potion::Potion(std::string name, std::string type, int healAmount):Item(name, type){
    m_healAmount = healAmount;
}

int Potion::getHealAmount(){
    return m_healAmount;
}