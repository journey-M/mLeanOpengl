aux_source_directory(. DIR_BLUEPRINT_SRCS)

add_library(engine_blueprint ${DIR_BLUEPRINT_SRCS})

target_link_libraries(engine_blueprint engine_tprdebug fmt)
