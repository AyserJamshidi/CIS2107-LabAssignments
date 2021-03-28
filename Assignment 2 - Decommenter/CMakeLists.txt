cmake_minimum_required(VERSION 3.17)
project(Assignment-2 C)

set(CMAKE_C_STANDARD 11)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/TestFile.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
add_executable(Assignment-2 Decommenter.c)