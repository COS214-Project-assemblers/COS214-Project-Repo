cmake_minimum_required(VERSION 3.20)
project(my_project)

# C++17 + warnings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -pedantic)

# Oat++
find_package(oatpp 1.4.0 REQUIRED)

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
  backend/game/TransactionStrategy.h
  backend/game/TransactionStrategy.cpp
  backend/game/Sale.h
  backend/game/Sale.cpp
  backend/game/Return.h
  backend/game/Return.cpp
  backend/game/Restock.h
  backend/game/Restock.cpp
  backend/game/PlantDied.h
  backend/game/PlantDied.cpp
  backend/game/Transaction.h
  backend/game/Transaction.cpp
  backend/game/TransactionMem.h
  backend/game/TransactionMem.cpp
  backend/game/TransactionHistory.h
  backend/game/TransactionHistory.cpp
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
  # backend/customer/Customer.h
  # backend/customer/Customer.cpp
  # backend/customer/AverageCustomer.h
  # backend/customer/AverageCustomer.cpp
  # backend/customer/IgnorantCustomer.h
  # backend/customer/IgnorantCustomer.cpp
  # backend/customer/GreenFingerCustomer.h
  # backend/customer/GreenFingerCustomer.cpp
  # backend/customer/CustomerVisitor.h
  # backend/customer/CustomerVisitor.cpp
)

add_executable(main
  backend/main.cpp
  ${SOURCES}
)

# Includes: add the API dir to both targets
target_include_directories(main  PRIVATE backend backend/API backend/game backend/plant backend/customer backend/greenhouse backend/Transaction)

# Link libs
target_link_libraries(main  PRIVATE oatpp::oatpp)
