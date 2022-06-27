project(leangl)
cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

AUX_SOURCE_DIRECTORY(src MAIN_CODE_SRCS)

add_executable(glrun main.cpp ${MAIN_CODE_SRCS})
target_link_libraries(glrun -lGL -lglfw -ldl )
