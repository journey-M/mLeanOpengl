aux_source_directory(. DIR_database_SRCS)

add_library(engine_database ${DIR_database_SRCS})
target_link_libraries(engine_database SQLite fmt engine_tprdebug)