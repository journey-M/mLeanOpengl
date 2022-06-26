aux_source_directory(. DIR_map_SRCS)
aux_source_directory(chunkCreateRelease DIR_chunksource_SRCS)

add_library(engine_map ${DIR_map_SRCS} ${DIR_chunksource_SRCS})