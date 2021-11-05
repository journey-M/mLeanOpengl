cmake_minimum_required(VERSION 3.2.0)

project(TowerDefends)

ADD_SUBDIRECTORY(engin)
aux_source_directory(logic LOGIC_SRC)

link_libraries(GL glfw dl pthread)

add_executable(TowerDefends ${LOGIC_SRC})
target_link_libraries(TowerDefends engin )
