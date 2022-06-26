aux_source_directory(. DIR_mgl_SRCS)

add_library(engine_mgl ${DIR_mgl_SRCS})
target_link_libraries(engine_mgl engine_tprdebug fmt)
