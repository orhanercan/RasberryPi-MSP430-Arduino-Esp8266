# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\RFIDHTTP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\RFIDHTTP_autogen.dir\\ParseCache.txt"
  "RFIDHTTP_autogen"
  )
endif()
