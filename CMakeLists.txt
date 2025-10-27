cmake_minimum_required(VERSION 3.20)
project(my_project)

# C++17 + warnings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -pedantic)

include (CTest)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/9706f75b8f91c52a3840cf5d878a7f37ea10ef00.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # Windows
FetchContent_MakeAvailable(googletest)

# JSON parsing library https://github.com/nlohmann/json?tab=readme-ov-file#package-managers
find_package(nlohmann_json 3.10 REQUIRED)

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
  backend/plant/Plant.h
  backend/plant/Plant.cpp
  backend/game/BasicLogger.h
  backend/game/BasicLogger.cpp
  backend/plant/PlantCreator.h
  backend/plant/PlantCreator.cpp
  backend/plant/FlowerCreator.h
  backend/plant/FlowerCreator.cpp
  backend/plant/SucculentCreator.h
  backend/plant/SucculentCreator.cpp
  backend/plant/TreeCreator.h
  backend/plant/TreeCreator.cpp
  backend/plant/Flower.h
  backend/plant/Flower.cpp
  backend/plant/Succulent.h
  backend/plant/Succulent.cpp
  backend/plant/Tree.h
  backend/plant/Tree.cpp
  backend/plant/NotSellable.h
  backend/plant/NotSellable.cpp
  backend/plant/PlantHealth.h
  backend/plant/PlantHealth.cpp
  backend/greenhouse/Greenhouse.h
  backend/greenhouse/Greenhouse.cpp
  backend/greenhouse/Inventory.h
  backend/greenhouse/Inventory.cpp
  backend/customer/Customer.h
  backend/customer/Customer.cpp
  backend/customer/IgnorantCustomer.h
  backend/customer/IgnorantCustomer.cpp
  backend/customer/AverageCustomer.h
  backend/customer/AverageCustomer.cpp
  backend/customer/GreenFingerCustomer.h
  backend/customer/GreenFingerCustomer.cpp
  backend/customer/CustomerVisitor.h
  backend/customer/CustomerVisitor.cpp
  backend/customer/VisitAverageSpendCustomer.h
  backend/customer/VisitAverageSpendCustomer.cpp
  backend/customer/VisitBigSpendCustomer.h
  backend/customer/VisitBigSpendCustomer.cpp
  backend/customer/VisitLowSpendCustomer.h
  backend/customer/VisitLowSpendCustomer.cpp
  backend/game/GameConfiguration.h
  backend/game/JSONGameConfiguration.h
  backend/game/JSONGameConfiguration.cpp
  backend/game/EnvironmentInitializer.h
  backend/game/EnvironmentInitializer.cpp
  backend/game/LogDecorator.h
  backend/game/LogDecorator.cpp
  backend/game/CoutAndLog.h
  backend/game/CoutAndLog.cpp
)

add_executable(g_test
  tests/unitTests.cpp
  ${SOURCES}
)

set(MEMORYCHECK_COMMAND "valgrind")
set(MEMORYCHECK_COMMAND_OPTIONS
    "--leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1")

add_custom_target(memcheck
  COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure --test-action MemCheck
  DEPENDS g_test
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "CTest MemCheck (Valgrind) on all tests"
)

# Includes: add the API dir to both targets
# target_include_directories(main  PRIVATE backend backend/API backend/game backend/plant backend/customer backend/greenhouse backend/transaction)
target_include_directories(g_test PRIVATE backend tests backend/API backend/game backend/plant backend/customer backend/greenhouse backend/transaction)

# Link libs
# target_link_libraries(main PRIVATE)
target_link_libraries(g_test PRIVATE GTest::gtest_main nlohmann_json::nlohmann_json)

target_compile_definitions(g_test PRIVATE
    ROOT_BUILD_DIR="${CMAKE_BINARY_DIR}"
    ROOT_SOURCE_DIR="${CMAKE_SOURCE_DIR}"
)

include(GoogleTest)
gtest_discover_tests(g_test)
