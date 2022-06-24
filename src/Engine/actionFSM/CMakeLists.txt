aux_source_directory(. DIR_action_FSM_SRCS)

add_library(engine_actionfsm ${DIR_action_FSM_SRCS})
target_include_directories(engine_actionfsm PRIVATE . ../tools ../tprDebug)