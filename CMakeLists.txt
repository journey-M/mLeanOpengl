project(leangl)
cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories(. include)
link_directories(third-libs)

AUX_SOURCE_DIRECTORY(src MAIN_CODE_SRCS)
AUX_SOURCE_DIRECTORY(src/lights MAIN_LIGHTS_SRCS)
AUX_SOURCE_DIRECTORY(src/model MAIN_MODEL_SRCS)
AUX_SOURCE_DIRECTORY(src/advancegl ADVANCEGL_SRCS)



add_executable(glrun main.cpp ${MAIN_CODE_SRCS} ${MAIN_LIGHTS_SRCS} ${MAIN_MODEL_SRCS} ${ADVANCEGL_SRCS})
target_link_libraries(glrun -lGL -lglfw -ldl -lassimp )
