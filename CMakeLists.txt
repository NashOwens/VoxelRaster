cmake_minimum_required(VERSION 3.13)
project(VoxelRaster VERSION 0.1.0)

add_subdirectory(src)

set(glm_DIR, /usr/local/lib/glm/cmake/glm)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(run src/main.cpp)

target_include_directories(Utils PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils)

target_include_directories(Shape PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes)

target_include_directories(Cube PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes)

target_include_directories(Obj PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes)

target_include_directories(Pyramid PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes)

target_link_libraries(run 
PRIVATE
glfw
glm::glm
GL
GLEW
Utils
Shape
Cube
Obj
Pyramid
Sect
userInput
)
