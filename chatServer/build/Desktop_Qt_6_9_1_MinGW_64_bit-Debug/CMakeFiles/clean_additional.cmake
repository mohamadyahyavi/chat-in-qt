# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
<<<<<<< HEAD
  "CMakeFiles\\chatServer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\chatServer_autogen.dir\\ParseCache.txt"
  "chatServer_autogen"
=======
  "CMakeFiles\\project1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\project1_autogen.dir\\ParseCache.txt"
  "project1_autogen"
>>>>>>> 44c820c0cd4829b4cbd1ca3039dab8643aa35f5f
  )
endif()
