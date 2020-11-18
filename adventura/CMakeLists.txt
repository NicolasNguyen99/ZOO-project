cmake_minimum_required(VERSION 3.17)
project(adventura)

set(CMAKE_CXX_STANDARD 14)

add_executable(adventura main.cpp Map.cpp Map.h Room.cpp Room.h Enemy.cpp Enemy.h Hero.cpp Hero.h Team.cpp Team.h Inventory.cpp Inventory.h Item.cpp Item.h)