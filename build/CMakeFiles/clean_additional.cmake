# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/DataVisualizer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/DataVisualizer_autogen.dir/ParseCache.txt"
  "DataVisualizer_autogen"
  )
endif()
