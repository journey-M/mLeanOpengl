cmake_minimum_required(VERSION 3.10)

project (leanOpenGL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions("-Wall -g")

#target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}")

aux_source_directory(src DIR_LIB_SRCS)
add_library (sublib ${DIR_LIB_SRCS})

add_executable(main main.cpp)
target_link_libraries(main sublib glfw)
