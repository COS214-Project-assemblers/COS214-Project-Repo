cmake_minimum_required(VERSION 3.20)
project(my_project)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/9706f75b8f91c52a3840cf5d878a7f37ea10ef00.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(oatpp 1.4.0 REQUIRED)

enable_testing()

SET(SOURCES APIDto.h APIController.h APIController.cpp APIComponent.h APIComponent.cpp API.h API.cpp)

add_executable(
  g_test
  # AllTest.cpp
  ${SOURCES}
)

add_executable(
    main 
    main.cpp
    ${SOURCES}
)

target_include_directories(main  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(g_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(main PRIVATE oatpp::oatpp)

target_link_libraries(g_test PRIVATE oatpp::oatpp GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(g_test)