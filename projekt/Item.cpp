//
// Created by Nicolas Nguyen on 03/12/2020.
//

#include "Item.h"

Item::Item(std::string name, std::string type){
    m_name = name;
}

std::string Item::getName(){
    return m_name;
}

std::string Item::getType(){
    return m_type;
}
