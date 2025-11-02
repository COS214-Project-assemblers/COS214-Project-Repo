*This document details how to build the project using CMake, set up and use Google Tests for the project repository and documents the CI pipeline.*

### Setting up the enviroment
This assumes that you are using a Debian based (i.e. Ubuntu) distro. WSL is fine, basically Linux VM (cries in overhead).

Installing CMake and Ninja 

```sh
sudo apt install -y cmake
sudo apt install -y ninja-build
```

Done!
### Explaining CMakeLists.txt
If you want to know whats going on and, like me, your favorite pass time is reading docs, click [here](https://cmake.org/cmake/help/latest/index.html). Not gonna rewrite existing docs here.

However it is only strictly necessary to understand the following:

In the `CMakeLists` file, there is a section that defines how `.cpp` files are linked to produce executable's. 

```
add_executable(
  g_test
  AllTest.cpp
  ${SOURCES}
)

add_executable(
    main
    main.cpp
    ${SOURCES}
)
```

Here AllTest.cpp along with `$SOURCES` is compiled and linked to the g_test executable and main.cpp along with `$SOURCES` compiled and linked to the main executable. It is important to separate main and test, since both should have separate `main()` functions, which the linker recognizes as the program entry point, there can only be one entry point

`$SOURCES` is a CMake variable that will contain all of our source `.cpp` and `.h` file (with CMake, `.h` files are not strictly necessary but often included for consistency)

```
SET(SOURCES example.cpp)
```

All `.cpp` and `.h` files created should be manually appended to the list. The argument as to why this is not automated can be found [here](https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak/1060061#1060061).

### Building with CMake
First, create a build directory that will contain all executable's and CMake dependencies.

```shell
mkdir build
```

Initialize the project

```sh
cmake -S . -B build
```

Build the project

```sh
cmake --build build
```

The executable's can now be found in the `build directory`

```sh
cd build && ls
```

To run the tests

```sh
cd build && ctest
```

### CI

Auto run tests on PR opened for merging into `main`, `dev`

Workflow `.github/workflows/c-cpp.yaml`

```yml
name: C/C++ CI Automatic Testing

on:
  push:
    branches:
      - main
      - dev
  pull_request:
    branches:
      - main
      - dev

jobs:
  build:

    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v4
    - name: Make buid directory
      run: cmake -S . -B build_test
    - name: Build
      run: cmake --build build_test
    - name: Run tests
      run: cd build_test && ctest
```

