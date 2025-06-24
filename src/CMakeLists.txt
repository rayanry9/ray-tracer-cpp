add_library(vector3 STATIC ./vector3.cpp
                           "${PROJECT_SOURCE_DIR}/include/vector3.h")
target_include_directories(vector3 PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(color STATIC ./color.cpp "${PROJECT_SOURCE_DIR}/include/color.h")
target_include_directories(color PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(object STATIC ./object.cpp "${PROJECT_SOURCE_DIR}/include/object.h")
target_include_directories(object PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(object PUBLIC vector3)

add_library(camera STATIC ./camera.cpp "${PROJECT_SOURCE_DIR}/include/camera.h")
target_include_directories(camera PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(camera PUBLIC object vector3 ray world color)

add_library(ray STATIC ./ray.cpp "${PROJECT_SOURCE_DIR}/include/ray.h")
target_include_directories(ray PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(ray PUBLIC object mesh world color vector3)

add_library(mesh STATIC ./mesh.cpp "${PROJECT_SOURCE_DIR}/include/mesh.h")
target_include_directories(mesh PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(mesh PUBLIC object vector3 ray color)

add_library(world STATIC ./world.cpp "${PROJECT_SOURCE_DIR}/include/world.h")
target_include_directories(world PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(world PUBLIC mesh camera light)

add_library(sphere STATIC ./sphere.cpp "${PROJECT_SOURCE_DIR}/include/sphere.h")
target_include_directories(sphere PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(sphere PUBLIC color mesh ray vector3)

add_library(light STATIC ./light.cpp "${PROJECT_SOURCE_DIR}/include/light.h")
target_include_directories(light PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(light PUBLIC object vector3 ray)

add_library(plane STATIC ./plane.cpp "${PROJECT_SOURCE_DIR}/include/plane.h")
target_include_directories(plane PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(plane PUBLIC mesh vector3 color ray)

add_executable(ray_tracer ./main.cpp)
target_link_libraries(
  ray_tracer
  PUBLIC color
         camera
         plane
         sphere
         light
         vector3
         world)

set_target_properties(ray_tracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                            ${CMAKE_BINARY_DIR}/bin)
