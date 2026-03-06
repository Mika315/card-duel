cmake_minimum_required(VERSION 3.28)
project(CardDuel)

# ask CMake to emit a compile_commands.json file for IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CardDuel
    main.cpp
    Card.cpp
    Deck.cpp
    Set.cpp
    Character.cpp
    Warrior.cpp
    Wizard.cpp
    Archer.cpp
    Enemy.cpp
    Exceptions.cpp
)