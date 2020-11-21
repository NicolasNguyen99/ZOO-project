//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Item.h"

Item::Item(std::string name, typeOfItem type){
    m_name = name;
    m_type = type;
}

std::string Item::getName(){
    return m_name;
}

typeOfItem Item::getType(){
    return m_type;
}
