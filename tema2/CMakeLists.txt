cmake_minimum_required(VERSION 3.0)
project(tema2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_library(marketcore STATIC
    src/Produs.cpp
    src/Inventory.cpp
    src/Logger.cpp
)

add_executable(tema2
    src/main.cpp
)

target_link_libraries(tema2 PRIVATE marketcore)