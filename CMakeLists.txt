cmake_minimum_required(VERSION 3.10)
project(BuildingBlocks)

set(CMAKE_CXX_STANDARD 11)

add_executable(BuildingBlocks main.cpp Block.h Blockchain.h sha256.h sha256.cpp Block.cpp Blockchain.cpp)