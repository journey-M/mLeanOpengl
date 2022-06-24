aux_source_directory(. DIR_ACTION_SWITCH_SRCS)

add_library(engine_actionswitch ${DIR_ACTION_SWITCH_SRCS})
target_include_directories(engine_actionswitch PRIVATE . ../tools ../tprDebug ../tprDebug)