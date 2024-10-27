cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Pacman)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Add the executable
add_executable(pacman main.cpp)

# Link SFML libraries
target_link_libraries(pacman sfml-system sfml-window sfml-graphics sfml-audio)