aux_source_directory(. DIR_CAMERA_SRCS)

add_library(engine_camera ${DIR_CAMERA_SRCS})
target_include_directories(engine_camera PRIVATE  ../../../deps/glad/include)