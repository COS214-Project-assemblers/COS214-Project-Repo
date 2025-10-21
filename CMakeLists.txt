cmake_minimum_required(VERSION 3.20)
project(my_project)

# C++17 + warnings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -pedantic)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/9706f75b8f91c52a3840cf5d878a7f37ea10ef00.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # Windows
FetchContent_MakeAvailable(googletest)

# Oat++
# find_package(oatpp 1.4.0 REQUIRED)

enable_testing()

set(SOURCES
  # backend/API/APIDto.h
  # backend/API/APIController.h
  # backend/API/APIController.cpp
  # backend/API/APIComponent.h
  # backend/API/APIComponent.cpp
  # backend/API/API.h
  # backend/API/API.cpp
  backend/game/Game.cpp
  backend/game/Game.h
  backend/game/MenuOption.cpp
  backend/game/MenuOption.h
  backend/game/NewGameOption.h
  backend/game/NewGameOption.cpp
  backend/game/PlayerMenu.h
  backend/game/PlayerMenu.cpp
  backend/game/Logger.h
  # backend/game/Logger.cpp
  backend/game/BasicLogger.h
  backend/game/BasicLogger.cpp
  # backend/plant/PlantCreator.h
  # backend/plant/PlantCreator.cpp
  # backend/plant/FlowerCreator.h
  # backend/plant/FlowerCreator.cpp
  # backend/plant/SucculentCreator.h
  # backend/plant/SucculentCreator.cpp
  # backend/plant/TreeCreator.h
  # backend/plant/TreeCreator.cpp
  # backend/plant/Flower.h
  # backend/plant/Flower.cpp
  # backend/plant/Succulent.h
  # backend/plant/Succulent.cpp
  # backend/plant/Tree.h
  # backend/plant/Tree.cpp
)

add_executable(g_test
  tests/unitTests.cpp
  ${SOURCES}
)

# add_executable(main
#   backend/main.cpp
#   ${SOURCES}
# )

# Includes: add the API dir to both targets
# target_include_directories(main  PRIVATE backend backend/API backend/game backend/plant backend/customer backend/greenhouse backend/transaction)
target_include_directories(g_test PRIVATE backend tests backend/API backend/game backend/plant backend/customer backend/greenhouse backend/transaction)

# Link libs
# target_link_libraries(main PRIVATE)
target_link_libraries(g_test PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(g_test)
