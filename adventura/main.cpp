#include <iostream>
#include "Game.h"

int main() {
    Game* game = new Game();
    game->printMap();
    game->printMovementOptions();
    std::cout << game->getCurrentCoor().x;
    std::cout << game->getCurrentCoor().y << std::endl;
    game->moveTeam(N);
    std::cout << game->getCurrentCoor().x;
    std::cout << game->getCurrentCoor().y << std::endl;
    game->printMovementOptions();
    game->moveTeam(E);
    std::cout << game->getCurrentCoor().x;
    std::cout << game->getCurrentCoor().y << std::endl;
    game->printMovementOptions();
    game->moveTeam(W);
    std::cout << game->getCurrentCoor().x;
    std::cout << game->getCurrentCoor().y << std::endl;
    game->printMovementOptions();
    return 0;
}
