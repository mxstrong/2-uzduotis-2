cmake_minimum_required(VERSION 3.10)

# set the project name
project(Vector)

# set source files
set(SOURCE Main.cpp GenerateFile.cpp PrintResults.cpp Random.cpp ReadData.cpp Student.cpp)

# add headers
include_directories(${PROJECT_SOURCE_DIR})

# add the executable
add_executable(Vector ${SOURCE})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)