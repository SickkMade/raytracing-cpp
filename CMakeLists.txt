cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all source files in the current directory
file(GLOB SOURCES "*.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})