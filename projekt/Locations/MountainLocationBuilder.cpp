//
// Created by Nicolas Nguyen on 06/12/2020.
//

#include "MountainLocationBuilder.h"

void MountainLocationBuilder::createLocation(){
    m_location = new Location("Mountains of Destiny", 5);
    MatrixOfAsciiArt rowPattern;
    rowPattern.at(0) =m_location->getName();
    rowPattern.at(1) ="     /\\             ";
    rowPattern.at(2) ="    /**\\            ";
    rowPattern.at(3) ="   /****\\  /\\       ";
    rowPattern.at(4) ="  /  /\\  \\/  \\/\\    ";
    rowPattern.at(5) ="_/__/__\\_/___/__\\_  ";
    m_location->setPattern(rowPattern);
    m_location->setBonusOfLocation({-2*m_location->getLocationLevel(), -1*m_location->getLocationLevel(), 0});
    m_location->setType(locationType::Mountain);
}

void MountainLocationBuilder::createTiles(){
    std::vector<Tile*> row1;
    std::vector<Tile*> row2;
    std::vector<Tile*> row3;

    row1.push_back(new Tile());row1.push_back(new Tile());row1.push_back(new Tile());
    row2.push_back(new Tile());row2.push_back(new Tile());row2.push_back(new Tile());
    row3.push_back(new Tile());row3.push_back(new Tile());row3.push_back(new Tile());

    m_tiles.push_back(row1);
    m_tiles.push_back(row2);
    m_tiles.push_back(row3);
}

void MountainLocationBuilder::spawnEnemies(){
//    m_tiles.at(1).at(1)->setEnemy(new Enemy(m_location->getLocationLevel()));
//    m_tiles.at(2).at(2)->setEnemy(new Enemy(m_location->getLocationLevel()));
//    m_tiles.at(2).at(1)->setEnemy(new Enemy(m_location->getLocationLevel()));
}

void MountainLocationBuilder::spawnChests(){

}