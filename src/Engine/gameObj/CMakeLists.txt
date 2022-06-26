aux_source_directory(. DIR_gameobj_SRCS)
aux_source_directory(createGo DIR_createGo_SRCS)
aux_source_directory(goDataForCreate DIR_goDataforJson_SRCS)

add_library(engine_gameobj ${DIR_gameobj_SRCS} ${DIR_createGo_SRCS} ${DIR_goDataforJson_SRCS} )
target_link_libraries(engine_gameobj engine_tprdebug fmt engine_move engine_camera engine_collision)