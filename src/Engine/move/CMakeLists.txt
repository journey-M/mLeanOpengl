aux_source_directory(. DIR_move_SRCS)

add_library(engine_move  ${DIR_move_SRCS})
target_link_libraries(engine_move engine_tprdebug fmt)
