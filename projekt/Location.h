//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_LOCATION_H
#define PROJEKT_LOCATION_H
#include <vector>
#include <array>
#include "Tile.h"

enum class locationType{Forest, Mountain, Swamp, Desert};
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
typedef  std::vector<std::vector<Tile*>> matrixOfTiles;
struct weaponBonusLocation{
    int meleeWeapon;
    int rangeWeapon;
    int magicWeapon;
};

class Location {
    //tyto vlastnosti budou ruzne podle buildru lokaci
    locationType m_type;
    std::array<std::string,5> m_pattern;
    int m_locationLevel;

    static positionCoor m_currentCoorTile;
    Tile* m_currentTile;
    weaponBonusLocation m_bonusOfLocation;
    matrixOfTiles m_tiles;
    std::string m_name;

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

    void setPattern(std::array<std::string,5> rowPattern);
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
