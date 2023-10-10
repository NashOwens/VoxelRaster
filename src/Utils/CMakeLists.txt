add_library(Utils STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils.h
    )

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)