# Minimum version of CMake required
cmake_minimum_required(VERSION 3.16)

# Define the project name
project(DataVisualizer LANGUAGES CXX)

# Set the C++ standard 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Qt6 COMPONENTS Core Widgets Charts REQUIRED)

# 2. Define the Executable Target 
qt_add_executable(DataVisualizer main.cpp DataGenerator.cpp)

# 3. Link Libraries 
target_link_libraries(DataVisualizer PRIVATE Qt6::Core Qt6::Widgets Qt6::Charts)

set_target_properties(DataVisualizer PROPERTIES 
    AUTOUIC ON
    AUTOMOC ON
    AUTORCC ON
)
