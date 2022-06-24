aux_source_directory(. DIR_ANIMFRAMESET_SRCS)

add_library(engine_animframset ${DIR_ANIMFRAMESET_SRCS})
target_include_directories(engine_animframset PRIVATE . ../tools)