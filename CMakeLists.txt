cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/9706f75b8f91c52a3840cf5d878a7f37ea10ef00.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

SET(SOURCES Game.cpp)

add_executable(
  g_test
  # AllTest.cpp
  ${SOURCES}
)

add_executable(
    main 
    # main.cpp
    ${SOURCES}
)

target_link_libraries(
  g_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(g_test)