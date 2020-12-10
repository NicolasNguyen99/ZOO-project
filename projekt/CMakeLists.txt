cmake_minimum_required(VERSION 3.17)
project(projekt)

include_directories(Location)

set(CMAKE_CXX_STANDARD 14)

add_executable(projekt main.cpp Tile.cpp Tile.h Map.cpp Map.h Location/Location.cpp Location/Location.h Enemy.cpp Enemy.h Character.cpp Character.h Hero.cpp Hero.h Game.cpp Game.h Armor.cpp Armor.h Potion.cpp Potion.h Weapon.cpp Weapon.h Item.cpp Item.h Chest.cpp Chest.h Location/LocationBuilder.cpp Location/LocationBuilder.h Location/LocationDirector.cpp Location/LocationDirector.h Location/ForestLocationBuilder.cpp Location/ForestLocationBuilder.h Location/MountainLocationBuilder.cpp Location/MountainLocationBuilder.h Location/SwampLocationBuilder.cpp Location/SwampLocationBuilder.h Location/DesertLocationBuilder.cpp Location/DesertLocationBuilder.h Location/HellLocationBuilder.cpp Location/HellLocationBuilder.h Location/PlainLocationBuilder.cpp Location/PlainLocationBuilder.h Location/CastleLocationBuilder.cpp Location/CastleLocationBuilder.h Location/CaveLocationBuilder.cpp Location/CaveLocationBuilder.h Location/HeavenLocationBuilder.cpp Location/HeavenLocationBuilder.h)