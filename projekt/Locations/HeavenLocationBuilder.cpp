//
// Created by Nicolas Nguyen on 08/12/2020.
//

#include "HeavenLocationBuilder.h"

void HeavenLocationBuilder::createLocation(){
    m_location = new Location(" Heaven of Elysium  ", 1);
    MatrixOfAsciiArt rowPattern;
    rowPattern.at(0) =m_location->getName();
    rowPattern.at(1) ="                    ";
    rowPattern.at(2) ="                    ";
    rowPattern.at(3) ="                    ";
    rowPattern.at(4) ="                    ";
    rowPattern.at(5) ="                    ";

//    rowPattern.at(1) =" *  *┌─────┐ *  *   ";
//    rowPattern.at(2) ="  *  │    ~│  *     ";
//    rowPattern.at(3) =" *  *│     │ *  *   ";
//    rowPattern.at(4) =" @@@┌┴─────┴┐@@@    ";
//    rowPattern.at(5) =" @@┌┴───────┴┐@@    ";
    m_location->setPattern(rowPattern);
    m_location->setBonusOfLocation({-2*m_location->getLocationLevel(), -1*m_location->getLocationLevel(), 0});
    m_location->setType(locationType::Heaven);
}

void HeavenLocationBuilder::createTiles(){
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

void HeavenLocationBuilder::spawnEnemies(){
    int locationLevel = m_location->getLocationLevel();
    m_tiles.at(0).at(1)->setEnemy(new Enemy(locationLevel));
    m_tiles.at(1).at(2)->setEnemy(new Enemy(locationLevel));
    m_tiles.at(2).at(1)->setEnemy(new Enemy(locationLevel));
}

void HeavenLocationBuilder::spawnChests(){
    m_tiles.at(0).at(1)->setChest(new Chest(new Weapon("Stone axe", "Light axe", 30)));
    m_tiles.at(2).at(2)->setChest(new Chest(new Armor("Light armor", 30)));
    m_tiles.at(0).at(0)->setChest(new Chest(new Potion("Medium heal potion", "Heal potion", 15)));
}