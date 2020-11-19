//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Team.h"

Team::Team(){

}

void Team::moveTeam(std::vector<std::vector<Room*>> &rooms, Room* &currentRoom, std::array<int, 2> &currentCoor, movementDirection direction){
//   N x-- y=y
//   E x=x y++
//   S x++ y=y
//   W x=x y--
    if(direction == N){
        currentCoor[0] = currentCoor.at(0)-1;
        currentRoom = rooms.at(currentCoor[0]).at(currentCoor[1]);
    } else {
        if(direction == E){
            currentCoor[1] = currentCoor.at(1)+1;
            currentRoom = rooms.at(currentCoor[0]).at(currentCoor[1]);
        } else {
            if(direction == S){
                currentCoor[0] = currentCoor.at(0)+1;
                currentRoom = rooms.at(currentCoor[0]).at(currentCoor[1]);
            } else {
                if(direction == W) {
                    currentCoor[1] = currentCoor.at(1) - 1;
                    currentRoom = rooms.at(currentCoor[0]).at(currentCoor[1]);
                }
            }
        }
    }
}