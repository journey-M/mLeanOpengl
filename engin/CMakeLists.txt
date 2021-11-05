cmake_minimum_required(VERSION 3.2.0)

project(engin)
SET(CMAKE_BUILE_TYPE DEBUG)
add_definitions("-Wall -g -static")

aux_source_directory(. ENGIN_SRC)

ADD_SUBDIRECTORY(graphic_glsl4.0)
ADD_SUBDIRECTORY(third-libs)

link_libraries(GL glfw dl pthread)

add_library(engin ${ENGIN_SRC})

target_link_libraries(engin gl40 json11 tinygltf)
