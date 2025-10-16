cmake_minimum_required(VERSION 3.10)

project(CoffePayment VERSION 1.0 LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(CoffeePayment 
    src/main.cpp
    lib/CoffeeShop.cpp
    lib/PaymentStrategy.cpp
)