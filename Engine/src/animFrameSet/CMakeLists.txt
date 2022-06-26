aux_source_directory(. DIR_ANIMFRAMESET_SRCS)

add_library(engine_animframset ${DIR_ANIMFRAMESET_SRCS})

target_link_libraries(engine_animframset  fmt engine_tprdebug)
