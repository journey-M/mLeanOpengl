aux_source_directory(. DIR_tools_SRCS)

add_library(engine_tools ${DIR_tools_SRCS})
target_link_libraries(engine_tools fmt engine_tprdebug)