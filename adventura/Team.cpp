//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Team.h"

Team::Team(){

}

void Team::moveTeam(std::vector<std::vector<Room*>> &rooms, Room* &currentRoom, positionCoor &currentCoor, movementDirection direction){
//   N x-- y=y
//   E x=x y++
//   S x++ y=y
//   W x=x y--
    if(direction == N){
        currentCoor.x = currentCoor.x-1;
        currentRoom = rooms.at(currentCoor.x).at(currentCoor.y);
    } else {
        if(direction == E){
            currentCoor.y = currentCoor.y+1;
            currentRoom = rooms.at(currentCoor.x).at(currentCoor.y);
        } else {
            if(direction == S){
                currentCoor.x = currentCoor.y+1;
                currentRoom = rooms.at(currentCoor.x).at(currentCoor.y);
            } else {
                if(direction == W) {
                    currentCoor.y = currentCoor.y-1;
                    currentRoom = rooms.at(currentCoor.x).at(currentCoor.y);
                }
            }
        }
    }
}