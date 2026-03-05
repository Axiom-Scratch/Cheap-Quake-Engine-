cmake_minimum_required(VERSION 3.20)
project(AxiomEngine LANGUAGES C CXX)

set(CMAKE_VS_GLOBAL_EnableBuildInsights OFF CACHE BOOL "" FORCE)
set(CMAKE_VS_GLOBAL_EnableCodeAnalysis OFF CACHE BOOL "" FORCE)
set(CMAKE_VS_GLOBAL_EnablePerfPowerProfile OFF CACHE BOOL "" FORCE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/spdlog)
add_subdirectory(Axiom)
add_subdirectory(Sandbox)
