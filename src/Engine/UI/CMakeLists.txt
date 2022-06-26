aux_source_directory(. DIR_ui_SRCS)

add_library(engine_ui ${DIR_ui_SRCS})
target_link_libraries(engine_ui engine_tprdebug fmt engine_mesh)