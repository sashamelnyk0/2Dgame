cmake_minimum_required(VERSION 3.24)
project(Gra)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(
        Gra main.cpp
        Game.h
        Game.cpp
        Player.h
        Player.cpp
        Bullet.h
        Bullet.cpp
        Enemy.h
        Enemy.cpp
        Enemy2.h
        Enemy2.cpp
        Perks.h
        Perks.cpp
        Icons.h
        Icons.cpp
        StartMenu.h
        StartMenu.cpp
        RecordWindow.h
        RecordWindow.cpp
        RecordWindow.cpp
        Store.h
        Store.cpp
)
target_link_libraries(Gra sfml-graphics)