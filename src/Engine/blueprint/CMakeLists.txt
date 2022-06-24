aux_source_directory(. DIR_BLUEPRINT_SRCS)

add_library(engine_blueprint ${DIR_BLUEPRINT_SRCS})
target_include_directories(engine_blueprint PRIVATE . ../tools ../tprDebug)