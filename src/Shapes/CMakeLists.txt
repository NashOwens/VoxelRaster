add_library(Cube STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Cube.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Cube.h
)

add_library(Obj STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Obj.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Obj.h
)

add_library(Pyramid STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Pyramid.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Pyramid.h
)

add_library(Shape STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Shape.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Shape.h
)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

