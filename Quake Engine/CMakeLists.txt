# CMakeList.txt : CMake project for Quake Engine, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeTarget "Quake Engine.cpp" "Quake Engine.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
