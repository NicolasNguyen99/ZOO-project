//
// Created by Nicolas Nguyen on 03/12/2020.
//

#include "Item.h"

Item::Item(std::string name, std::string type){
    m_name = name;
    m_type = type;
}

std::string Item::getName(){
    return m_name;
}

std::string Item::getType(){
    return m_type;
}

void Item::printItem(){
    std::cout << " -Name: " << m_name << "\n";
    std::cout << " -Type: " << m_type << "\n";
}
