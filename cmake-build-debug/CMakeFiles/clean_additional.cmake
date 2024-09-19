# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Blackjack_autogen"
  "CMakeFiles\\Blackjack_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Blackjack_autogen.dir\\ParseCache.txt"
  )
endif()
