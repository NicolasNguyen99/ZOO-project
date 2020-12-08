cmake_minimum_required(VERSION 3.17)
project(projekt)

set(CMAKE_CXX_STANDARD 14)

add_executable(projekt main.cpp Tile.cpp Tile.h Map.cpp Map.h Location.cpp Location.h Enemy.cpp Enemy.h Character.cpp Character.h Hero.cpp Hero.h Game.cpp Game.h Armor.cpp Armor.h Potion.cpp Potion.h Weapon.cpp Weapon.h Item.cpp Item.h Chest.cpp Chest.h LocationBuilder.cpp LocationBuilder.h LocationDirector.cpp LocationDirector.h ForestLocationBuilder.cpp ForestLocationBuilder.h MountainLocationBuilder.cpp MountainLocationBuilder.h SwampLocationBuilder.cpp SwampLocationBuilder.h DesertLocationBuilder.cpp DesertLocationBuilder.h HellLocationBuilder.cpp HellLocationBuilder.h PlainLocationBuilder.cpp PlainLocationBuilder.h CastleLocationBuilder.cpp CastleLocationBuilder.h CaveLocationBuilder.cpp CaveLocationBuilder.h HeavenLocationBuilder.cpp HeavenLocationBuilder.h)