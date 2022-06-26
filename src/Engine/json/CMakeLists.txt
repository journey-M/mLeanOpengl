aux_source_directory(. DIR_json_SRCS)

add_library(engine_json ${DIR_json_SRCS})
target_link_libraries(engine_json engine_tprdebug fmt)