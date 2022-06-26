aux_source_directory(. DIR_multithread_SRCS)
aux_source_directory(chunkCreate DIR_chunkcreate_SRCS)
aux_source_directory(ecoObjCreate DIR_ecoObjCreate_SRCS)

add_library(engine_multithread  ${DIR_multithread_SRCS} ${DIR_chunkcreate_SRCS} ${DIR_ecoObjCreate_SRCS})

target_link_libraries(engine_multithread fmt engine_tprdebug  engine_resource engine_ecosys engine_map)