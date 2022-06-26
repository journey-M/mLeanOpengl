aux_source_directory(. DIR_collision_SRCS)

add_library(engine_collision ${DIR_collision_SRCS} signInMapEnts/SignInMapEnts_Square_Type.cpp signInMapEnts/SignInMapEnts_Square.cpp)