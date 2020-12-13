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
struct availableMovement{
    bool N = false;
    bool E = false;
    bool S = false;
    bool W = false;
};
enum class sizeOfLocation{Small=3,Medium=4,Large=5};
struct positionCoor{
    int x;
    int y;
};
struct sizeOfMovement{
    int x;
    int y;
};
typedef std::array<std::string,asciiArtRows> matrixOfAsciiArt;
typedef  std::vector<std::vector<Tile*>> matrixOfTiles;
struct weaponBonusLocation{
    int meleeWeapon;
    int rangeWeapon;
    int magicWeapon;
};

class Location {
    std::string m_name;
    matrixOfTiles m_tiles;
    Tile* m_currentTile;
    static positionCoor m_currentCoorTile;
    int m_locationLevel;
    locationType m_type;
    matrixOfAsciiArt m_pattern;
    weaponBonusLocation m_bonusOfLocation;

public:
    Location(std::string name, int level);
    void printLocation(int rowNum);
    void printTileMap();
    void moveCurrentCoorTile(sizeOfMovement sizePosition);
    //void setCurrentCoorTile(positionCoor newPosition);
    availableMovement checkMovement(positionCoor coor, int range);
    positionCoor getTilepositionCoor();
    void setStartingTile();
    void setCurrentTile();
    objectsInTile getObjectsInTile();

    Enemy* getEnemy();
    void setPattern(matrixOfAsciiArt rowPattern);
    void setTiles(matrixOfTiles tiles);
    int getSize();
    void setBonusOfLocation(weaponBonusLocation bonus);
    weaponBonusLocation getBonusOfLocation();
    locationType getType();
    int getLocationLevel();
    std::string getName();
    void setType(locationType type);

};


#endif //PROJEKT_LOCATION_H
