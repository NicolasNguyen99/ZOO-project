//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_HERO_H
#define ADVENTURA_HERO_H

//enum movementDirection{N,E,S,W};

class Hero {
    int health;
    int strength;

public:
    Hero();
    void movement(char direction);
    void printMovementOptions();
    bool checkMovement(char direction);
};


#endif //ADVENTURA_HERO_H
