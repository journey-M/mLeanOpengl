cmake_minimum_required(VERSION 3.2.0)

project(TowerDefends)
SET(CMAKE_BUILE_TYPE DEBUG)
add_definitions("-Wall -g -static")

aux_source_directory(. APP_SRC)

ADD_SUBDIRECTORY(graphic_glsl4.0)

link_libraries(GL glfw dl pthread)

add_executable(main ${APP_SRC})

target_link_libraries(main gl40)
