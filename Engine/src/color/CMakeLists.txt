aux_source_directory(. DIR_color_SRCS)

add_library(engine_color ${DIR_color_SRCS})
target_link_libraries(engine_color fmt)