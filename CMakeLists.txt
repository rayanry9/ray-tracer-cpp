cmake_minimum_required(VERSION 3.15...4.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  RayTracer
  VERSION 1.0
  DESCRIPTION "Ray Tracer in a Weekend to learn C++ and CMake"
  LANGUAGES CXX)

include_directories("${PROJECT_SOURCE_DIR}/include")
add_subdirectory(src)
