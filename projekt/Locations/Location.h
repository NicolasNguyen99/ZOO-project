//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_LOCATION_H
#define PROJEKT_LOCATION_H
#include <vector>
#include <array>
#include "../Tile.h"

const int asciiArtRows = 6;
enum class locationType{Forest, Mountain, Swamp, Desert, Plain, Castle, Cave, Heaven, Hell};
enum class sizeOfLocation{Small=3,Medium=4,Large=5};

struct availableMovement{
    bool N = false;
    bool E = false;
    bool S = false;
    bool W = false;
};
struct positionCoor{
    int x;
    int y;
};
struct sizeOfMovement{
    int x;
    int y;
};
struct weaponBonusLocation{
    int meleeWeapon;
    int rangeWeapon;
    int magicWeapon;
};
typedef std::array<std::string,asciiArtRows> MatrixOfAsciiArt;
typedef  std::vector<std::vector<Tile*>> MatrixOfTiles;
typedef std::array<Tile*,3> TileStrip;

class Location {
    std::string m_name;
    MatrixOfTiles m_tiles;
    Tile* m_currentTile;
    static positionCoor s_currentCoorTile;
    int m_locationLevel;
    locationType m_type;
    MatrixOfAsciiArt m_pattern;
    weaponBonusLocation m_bonusOfLocation;

public:
    Location(std::string name, int level);
    void printLocation(int rowNum);
    void printTileMap(TileStrip topStrip, TileStrip bottomStrip, TileStrip rightStrip, TileStrip leftStrip);
    void moveCurrentCoorTile(sizeOfMovement sizePosition);
    availableMovement checkMovement(positionCoor coor, int range);
    positionCoor getTilepositionCoor();
    void setStartingTile();
    void setCurrentTile();
    objectsInTile getObjectsInTile();
    void removeChest();
    Enemy* getEnemy();
    void setPattern(MatrixOfAsciiArt rowPattern);
    void setTiles(MatrixOfTiles tiles);
    int getSize();
    void setBonusOfLocation(weaponBonusLocation bonus);
    weaponBonusLocation getBonusOfLocation();
    locationType getType();
    int getLocationLevel();
    std::string getName();
    void setType(locationType type);
    void killEnemy();
    void printEnemyStats();
    void setTileExploration();
    MatrixOfTiles getTiles();
    positionCoor getCurrentCoorTile();
};


#endif //PROJEKT_LOCATION_H
