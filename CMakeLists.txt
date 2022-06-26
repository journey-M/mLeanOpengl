project(trip)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(UNIX 1)

# 确认一些 变量值：
message(STATUS "[__INFO__] CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "[__INFO__] PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message(STATUS "[__INFO__] CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


#/代码中有些依赖  Script目录问题，需要解决，目前只能加.解决 
include_directories(.
Engine/include
third_libs/glm.9.9.5 
third_libs/magic_enum 
third_libs/glad/include 
third_libs/tprGeneral 
third_libs/stb_image 
third_libs/tprInUnix 
third_libs/tprGeneral 
third_libs/rapidjson)


get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> SET DEFAULT TO BEFORE, include_dirs=${dirs}")


add_subdirectory(third_libs/glad)
add_subdirectory(third_libs/tprGeneral)
add_subdirectory(third_libs/sqlite.3.28)
add_subdirectory(third_libs/fmt-6.1.2)
add_subdirectory(third_libs/tprInUnix)
add_subdirectory(third_libs/glfw_unix)
add_subdirectory(Engine)


FILE(GLOB_RECURSE PIXEL_FILES   
                        Script/*.cpp 
                        )
add_executable (tprpix ${PIXEL_FILES} )
target_link_libraries(tprpix
        tprGeneral
        tprInUnix
        glad
        glfw
        ${GLFW_LIBRARIES}
        SQLite
        fmt 
        engine_tprdebug engine_actionfsm engine_actionswitch  engine_animframset engine_blueprint 
engine_camera engine_circuitboard engine_collision engine_color engine_coordinate engine_database engine_dynamicprogram engine_ecosys
engine_fileio engine_gameobj engine_gameobj engine_mgl engine_input engine_json engine_map engine_mesh
engine_move engine_multithread engine_player engine_random engine_renderpool engine_resource engine_scene
engine_shaderprogram engine_time engine_tools  engine_ui  engine_vaovbo  engine_sys
)




