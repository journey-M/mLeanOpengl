aux_source_directory(. DIR_ecosys_SRCS)

add_library(engine_ecosys ${DIR_ecosys_SRCS} ecoObjBorder/EcoObjBorder.cpp ecoObjBorder/ecoObjBorderJson.cpp)
target_link_libraries(engine_ecosys fmt)