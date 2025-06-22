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
target_link_libraries(camera PUBLIC object vector3)

add_library(ray STATIC ./ray.cpp "${PROJECT_SOURCE_DIR}/include/ray.h")
target_include_directories(ray PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(ray PUBLIC object vector3)

add_library(world STATIC ./world.cpp "${PROJECT_SOURCE_DIR}/include/world.h")
target_include_directories(world PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(world PUBLIC ray object camera vector3)

add_executable(ray_tracer ./main.cpp)
target_link_libraries(ray_tracer PUBLIC vector3 color world ray)

set_target_properties(ray_tracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                            ${CMAKE_BINARY_DIR}/bin)
