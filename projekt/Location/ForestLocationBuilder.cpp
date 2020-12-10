//
// Created by Nicolas Nguyen on 06/12/2020.
//

#include "ForestLocationBuilder.h"

void ForestLocationBuilder::createLocation(){
    m_location = new Location("Forest of printers", 1);
    std::array<std::string,asciiArtRows> rowPattern;
    rowPattern.at(0) ="      " + m_location->getName() + "           ";
    rowPattern.at(1) ="            ,%%&%,  ";
    rowPattern.at(2) ="   /\\      %&%&%&%  ";
    rowPattern.at(3) ="  /**\\  /\\  %&%&&   ";
    rowPattern.at(4) =" /****\\/**\\  ||     ";
    rowPattern.at(5) ="___||___||___||___  ";
    m_location->setPattern(rowPattern);
    m_location->setBonusOfLocation({-2*m_location->getLocationLevel(), -1*m_location->getLocationLevel(), 0});
    m_location->setType(locationType::Forest);
}

void ForestLocationBuilder::createTiles(){
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

void ForestLocationBuilder::spawnEnemies(){
    m_tiles.at(1).at(1)->setEnemy(new Enemy());
    m_tiles.at(2).at(2)->setEnemy(new Enemy());
    m_tiles.at(2).at(1)->setEnemy(new Enemy());
}

void ForestLocationBuilder::spawnChests(){
    m_tiles.at(0).at(1)->setChest(new Chest(new Armor("Light Armor")));
}