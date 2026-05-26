cmake_minimum_required(VERSION 3.14)
project(ProgettoGradiente)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE__CXX_FLAGS "${CMAKE_CXX_FLAGS}-Wall")

find_package(Eigen3 REQUIRED)

add_executable(main main.cpp)


target_link_libraries(main PRIVATE Eigen3::Eigen)