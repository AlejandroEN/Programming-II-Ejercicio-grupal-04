cmake_minimum_required(VERSION 3.26)
project(Ejercicio_04_Grupal)

set(CMAKE_CXX_STANDARD 23)

add_executable(Ejercicio_04_Grupal
                main.cpp
                utils/utilities.cpp
                src/player.cpp
                src/menu.cpp
                src/dice.cpp)