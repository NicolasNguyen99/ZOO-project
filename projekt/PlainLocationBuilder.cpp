//
// Created by Nicolas Nguyen on 08/12/2020.
//

#include "PlainLocationBuilder.h"

void PlainLocationBuilder::createLocation(){
    m_location = new Location("Plains", 1);
    std::array<std::string,5> rowPattern;
    rowPattern.at(0) ="    ~~~     ~~~~    ";
    rowPattern.at(1) ="~~~             ~~  ";
    rowPattern.at(2) ="         ~~~~       ";
    rowPattern.at(3) ="~~ \\ \\//     / ~~   ";
    rowPattern.at(4) =".\\\\////../._//..__  ";
    m_location->setPattern(rowPattern);
    m_location->setBonusOfLocation({-2*m_location->getLocationLevel(), -1*m_location->getLocationLevel(), 0});
    m_location->setType(locationType::Plain);
}

void PlainLocationBuilder::createTiles(){
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

void PlainLocationBuilder::spawnEnemies(){
    m_tiles.at(1).at(1)->setEnemy(new Enemy());
    m_tiles.at(2).at(2)->setEnemy(new Enemy());
    m_tiles.at(2).at(1)->setEnemy(new Enemy());
}

void PlainLocationBuilder::spawnChests(){

}