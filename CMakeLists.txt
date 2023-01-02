cmake_minimum_required(VERSION 3.10)

project (leanOpenGL)

add_definitions("-Wall -g")

#target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}")

message("${DIR_LIB_SRCS}")


aux_source_directory(src DIR_LIB_SRCS)
add_library (sublib ${DIR_LIB_SRCS})

add_executable(main main.cpp)
#target_link_libraries(main sublib lavcodec lavformat lavutil)
target_link_libraries(main PUBLIC sublib glfw  m pthread avcodec avutil avformat avfilter swresample swscale )
#target_link_directories(main PRIVATE /usr/lib/ffmpeg4.4)

