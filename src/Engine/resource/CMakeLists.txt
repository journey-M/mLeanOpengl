aux_source_directory(. DIR_resource_SRCS)

add_library(engine_resource ${DIR_resource_SRCS})
target_link_libraries(engine_resource engine_multithread engine_tprdebug fmt engine_collision)
