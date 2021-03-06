//
// Created by Nicolas Nguyen on 08/12/2020.
//

#include "HellLocationBuilder.h"

void HellLocationBuilder::createLocation(){
    m_location = new Location(" Hell of Lost Souls ", 1);
    MatrixOfAsciiArt rowPattern;
    rowPattern.at(0) =m_location->getName();
    rowPattern.at(1) ="                    ";
    rowPattern.at(2) ="     ________      ";
    rowPattern.at(3) ="     |  |   |  / \\  ";
    rowPattern.at(4) =" / ) |     | / ))  ";
    rowPattern.at(5) =" \\)/ |      | \\(__/   ";
    m_location->setPattern(rowPattern);
    m_location->setBonusOfLocation({-2*m_location->getLocationLevel(), -1*m_location->getLocationLevel(), 0});
    m_location->setType(locationType::Hell);
}

void HellLocationBuilder::createTiles(){
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

void HellLocationBuilder::spawnEnemies(){
}

void HellLocationBuilder::spawnChests(){

}