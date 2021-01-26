//
// Created by Nicolas Nguyen on 08/12/2020.
//

#include "CastleLocationBuilder.h"

void CastleLocationBuilder::createLocation(){
    m_location = new Location("Ancient Castle", 1);
    MatrixOfAsciiArt rowPattern;
    rowPattern.at(0) =m_location->getName();
    rowPattern.at(1) ="   __    |~   __    ";
    rowPattern.at(2) ="  [__]---'---[__]   ";
    rowPattern.at(3) ="  |''|\"\" ` \"\"|''|   ";
    rowPattern.at(4) ="  |  |  /^\\  |  |   ";
    rowPattern.at(5) ="__|__|__|I|__|__|_  ";
    m_location->setPattern(rowPattern);
    m_location->setBonusOfLocation({-2*m_location->getLocationLevel(), -1*m_location->getLocationLevel(), 0});
    m_location->setType(locationType::Castle);
}

void CastleLocationBuilder::createTiles(){
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

void CastleLocationBuilder::spawnEnemies(){
//    m_tiles.at(2).at(0)->setEnemy(new Enemy(m_location->getLocationLevel()));
}

void CastleLocationBuilder::spawnChests(){

}