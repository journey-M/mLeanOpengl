aux_source_directory(. DIR_gameobj_SRCS)
aux_source_directory(createGo DIR_createGo_SRCS)
aux_source_directory(goDataForCreate DIR_goDataforJson_SRCS)

add_library(engine_gameobj ${DIR_gameobj_SRCS} ${DIR_createGo_SRCS} ${DIR_goDataforJson_SRCS} )