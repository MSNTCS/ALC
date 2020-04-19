cmake_minimum_required(VERSION 3.15)
project(ALC_)

set(CMAKE_CXX_STANDARD 20)

add_executable(ALC_ main.cpp DGraph.h Graph.h DGraph.cpp)

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()