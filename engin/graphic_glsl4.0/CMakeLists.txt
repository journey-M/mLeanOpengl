aux_source_directory(. SUB_SRC)

SET(CMAKE_BUILE_TYPE DEBUG)
add_definitions("-Wall -g -static")


link_libraries(GL glfw dl )


add_library(gl40 ${SUB_SRC})

