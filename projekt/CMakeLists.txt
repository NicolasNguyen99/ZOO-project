cmake_minimum_required(VERSION 3.17)
project(projekt)

set(CMAKE_CXX_STANDARD 14)

add_executable(projekt main.cpp Tile.cpp Tile.h Map.cpp Map.h Forrest.cpp Forrest.h Mountain.cpp Mountain.h Swamp.cpp Swamp.h Hero.cpp Hero.h Game.cpp Game.h Item.cpp Item.h)