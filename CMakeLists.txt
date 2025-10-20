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
find_package(oatpp 1.4.0 REQUIRED)

enable_testing()

set(SOURCES
  backend/API/APIDto.h
  backend/API/APIController.h
  backend/API/APIController.cpp
  backend/API/APIComponent.h
  backend/API/APIComponent.cpp
  backend/API/API.h
  backend/API/API.cpp
  backend/game/Game.cpp
  backend/game/Game.h
  backend/game/MenuOption.cpp
  backend/game/MenuOption.h
  backend/game/NewGameOption.h
  backend/game/NewGameOption.cpp
  backend/game/PlayerMenu.h
  backend/game/PlayerMenu.cpp
  backend/game/Logger.h
  backend/game/Logger.cpp
)

add_executable(g_test
  # AllTest.cpp
  ${SOURCES}
)

add_executable(main
  backend/main.cpp
  ${SOURCES}
)

# Includes: add the API dir to both targets
target_include_directories(main  PRIVATE backend/API)
target_include_directories(g_test PRIVATE backend/API)

# Link libs
target_link_libraries(main  PRIVATE oatpp::oatpp)
target_link_libraries(g_test PRIVATE oatpp::oatpp GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(g_test)
