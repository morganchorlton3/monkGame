cmake_minimum_required(VERSION 3.13)
project(Monk)

set(CMAKE_CXX_STANDARD 14)

add_executable(Monk main.cpp Character/Player.cpp Character/Player.h Dungon/Room.cpp Dungon/Room.h Character/Monster.cpp Character/Monster.h Tools/Weapon.cpp Tools/Weapon.h DrawingRooms/DrawingRooms.cpp DrawingRooms/Draw.cpp DrawingRooms/Draw.h)