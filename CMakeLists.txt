# Minimum version of CMake required
cmake_minimum_required(VERSION 3.16)

# Define the project name
project(DataVisualizer LANGUAGES CXX)

# Set the C++ standard 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. Find Qt6 Packages
find_package(Qt6 COMPONENTS Core Widgets Charts REQUIRED)

# 2. Define the Executable Target 
qt_add_executable(DataVisualizer 
main.cpp 
DataGenerator.cpp
MainWindow.cpp
)

# 3. Add Necessary Qt Include Directories
# This ensures the compiler can find the QtCharts namespace declarations correctly.
target_include_directories(DataVisualizer PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${Qt6_Core_INCLUDE_DIRS} 
    ${Qt6_Widgets_INCLUDE_DIRS}
    ${Qt6_Charts_INCLUDE_DIRS}
)

# 4. Link Libraries 
target_link_libraries(DataVisualizer PRIVATE 
    Qt6::Core 
    Qt6::Widgets 
    Qt6::Charts
)

# 5. Enable Qt Automation
set_target_properties(DataVisualizer PROPERTIES 
    AUTOUIC ON
    AUTOMOC ON
    AUTORCC ON
)