cmake_minimum_required(VERSION 3.24)
project(fileSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(fileSystem main.cpp FileSystem.cpp FileSystem.h Folder.cpp Folder.h File.cpp File.h FileSystem.cpp)