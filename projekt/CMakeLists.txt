cmake_minimum_required(VERSION 3.17)
project(projekt)

include_directories(Locations)
include_directories(Items)

set(CMAKE_CXX_STANDARD 14)

add_executable(projekt main.cpp Tile.cpp Tile.h Map.cpp Map.h Locations/Location.cpp Locations/Location.h Characters/Enemy.cpp Characters/Enemy.h Characters/Character.cpp Characters/Character.h Characters/Hero.cpp Characters/Hero.h Game.cpp Game.h Items/Armor.cpp Items/Armor.h Items/Potion.cpp Items/Potion.h Items/Weapon.cpp Items/Weapon.h Items/Item.cpp Items/Item.h Chest.cpp Chest.h Locations/LocationBuilder.cpp Locations/LocationBuilder.h Locations/LocationDirector.cpp Locations/LocationDirector.h Locations/ForestLocationBuilder.cpp Locations/ForestLocationBuilder.h Locations/MountainLocationBuilder.cpp Locations/MountainLocationBuilder.h Locations/SwampLocationBuilder.cpp Locations/SwampLocationBuilder.h Locations/DesertLocationBuilder.cpp Locations/DesertLocationBuilder.h Locations/HellLocationBuilder.cpp Locations/HellLocationBuilder.h Locations/PlainLocationBuilder.cpp Locations/PlainLocationBuilder.h Locations/CastleLocationBuilder.cpp Locations/CastleLocationBuilder.h Locations/CaveLocationBuilder.cpp Locations/CaveLocationBuilder.h Locations/HeavenLocationBuilder.cpp Locations/HeavenLocationBuilder.h Inventory.cpp Inventory.h GamePrepare.cpp GamePrepare.h)