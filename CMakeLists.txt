cmake_minimum_required(VERSION 3.28)
project(Prac2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Prac2
        Boatman.cpp
        Boatman.h
        BoatmanFactory.cpp
        BoatmanFactory.h
        Caretaker.cpp
        Caretaker.h
        Infantry.cpp
        Infantry.h
        InfantryFactory.cpp
        InfantryFactory.h
        Memento.cpp
        Memento.h
        ShieldBearer.cpp
        ShieldBearer.h
        ShieldBearerFactory.cpp
        ShieldBearerFactory.h
        SoldierFactory.cpp
        SoldierFactory.h
        Soldiers.cpp
        Soldiers.h)
