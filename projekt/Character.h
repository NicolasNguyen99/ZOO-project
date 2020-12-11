//
// Created by Nicolas Nguyen on 02/12/2020.
//

#ifndef PROJEKT_CHARACTER_H
#define PROJEKT_CHARACTER_H
#include <iostream>

class Character {
protected:
    std::string m_name;
    int m_health;
    int m_strength;

public:
    Character(std::string name);
    virtual std::string getName();
    virtual int getHealth();
    virtual int getStrength();
};


#endif //PROJEKT_CHARACTER_H
