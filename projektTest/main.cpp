#include <iostream>
#include "Game.h"

int main() {

//    Tile* tile = new Swamp(tileType::Swamp, false);
//    tile->printPattern();
//    Tile* tile1 = new Forrest(tileType::Forrest, false);
//    tile1->printPattern();
//    Tile* tile2 = new Mountain(tileType::Mountain, false);
//    tile2->printPattern();
    Game* game = new Game();
    game->printMap();
    game->printMovementOptions();
    game->moveHero(movementDirection::N);
    game->printMovementOptions();
    return 0;
}