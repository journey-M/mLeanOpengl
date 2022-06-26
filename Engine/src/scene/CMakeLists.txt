aux_source_directory(. DIR_scene_SRCS)
aux_source_directory(begin DIR_scene_begin_SRCS)
aux_source_directory(world DIR_scene_world_SRCS)

add_library(engine_scene ${DIR_scene_SRCS} ${DIR_scene_begin_SRCS} ${DIR_scene_world_SRCS})
target_link_libraries(engine_scene engine_dynamicprogram engine_ui engine_random engine_gameobj 
engine_map engine_resource)