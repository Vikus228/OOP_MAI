cmake_minimum_required(VERSION 3.10)
project(BalagurFate3)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_OSX_ARCHITECTURES "arm64")

include_directories(include)

add_executable(BalagurFate3
    src/main.cpp
    src/NPC.cpp
    src/NPCFactory.cpp
    src/BattleVisitor.cpp
    src/Observer.cpp
    src/Logger.cpp
    src/DungeonEditor.cpp
)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(DungeonEditorTest
    tests/DungeonEditorTest.cpp
    src/NPC.cpp
    src/NPCFactory.cpp
    src/BattleVisitor.cpp
    src/Observer.cpp
    src/Logger.cpp
    src/DungeonEditor.cpp
)

target_link_libraries(DungeonEditorTest ${GTEST_LIBRARIES} pthread)

add_test(NAME DungeonEditorTest COMMAND DungeonEditorTest)