cmake_minimum_required(VERSION 3.19)
project(Learning_MultiplayerGameProgramming)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(${PROJECT_NAME} src/main.cpp src/SocketAddress.cpp include/SocketAddress.hpp)