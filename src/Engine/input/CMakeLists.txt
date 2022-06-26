aux_source_directory(. DIR_input_SRCS)

add_library(engine_input ${DIR_input_SRCS})
target_link_libraries(engine_input engine_tprdebug fmt)