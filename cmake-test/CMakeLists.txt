cmake_minimum_required(VERSION 2.8)

SET(TARGET_NAME	cmake-test)
PROJECT(${TARGET_NAME})

SET(CMAKE_CXX_COMPILER "g++.exe")
SET(CMAKE_C_COMPILER "gcc.exe")

SET(CMAKE_C_FLAGS  "-g")

FILE(GLOB_RECURSE SRC_LIST "*.cpp" "*.c")
FILE(GLOB_RECURSE REMOVE_CMAKE "cmake-build-debug/*" "build/*")

message("SRC_LIST is:" ${SRC_LIST})
LIST(REMOVE_ITEM SRC_LIST ${REMOVE_CMAKE})

add_executable (${TARGET_NAME} ${SRC_LIST})

