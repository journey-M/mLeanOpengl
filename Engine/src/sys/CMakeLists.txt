aux_source_directory(. DIR_sys_SRCS)

add_library(engine_sys ${DIR_sys_SRCS})
target_link_libraries(engine_sys tprInUnix
        glad
        glfw
        ${GLFW_LIBRARIES}
        SQLite
        fmt 
        engine_tprdebug engine_actionfsm engine_actionswitch  engine_animframset engine_blueprint 
engine_camera engine_circuitboard engine_collision engine_color engine_coordinate engine_database engine_dynamicprogram engine_ecosys
engine_fileio engine_gameobj engine_gameobj engine_mgl engine_input engine_json engine_map engine_mesh
engine_move engine_multithread engine_player engine_random engine_renderpool engine_resource engine_scene
engine_shaderprogram engine_time engine_tools  engine_ui  engine_vaovbo)