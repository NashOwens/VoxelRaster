add_subdirectory(Utils)
add_subdirectory(Shapes)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_library(Sect STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Sect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sect.h
)

add_library(userInput STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/userInput.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/userInput.h
)