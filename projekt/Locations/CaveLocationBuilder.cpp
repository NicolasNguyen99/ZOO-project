//
// Created by Nicolas Nguyen on 08/12/2020.
//

#include "CaveLocationBuilder.h"

void CaveLocationBuilder::createLocation(){
    m_location = new Location("The Forgotten Cave", 1);
    MatrixOfAsciiArt rowPattern;
    rowPattern.at(0) =m_location->getName();
    rowPattern.at(1) ="   ___..-.          ";
    rowPattern.at(2) =" _/  __ \\_`-.__     ";
    rowPattern.at(3) ="/ .'/##\\_ `-.  \\   ";
    rowPattern.at(4) =".-_/#@@##\\  /-'`\\   ";
    rowPattern.at(5) =" /########\\_  \\._\\  ";
    m_location->setPattern(rowPattern);
    m_location->setBonusOfLocation({-2*m_location->getLocationLevel(), -1*m_location->getLocationLevel(), 0});
    m_location->setType(locationType::Cave);
}

void CaveLocationBuilder::createTiles(){
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

void CaveLocationBuilder::spawnEnemies(){
}

void CaveLocationBuilder::spawnChests(){

}