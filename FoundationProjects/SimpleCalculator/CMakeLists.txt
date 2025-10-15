cmake_minimum_required(VERSION 3.10)

project(SimpleCalculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(SimpleCalculator
    src/main.cpp
    lib/add.cpp
    lib/sub.cpp
    lib/mul.cpp
    lib/div.cpp
    lib/mod.cpp
)
