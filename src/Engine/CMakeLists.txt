
project(trip)

cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)



set(UNIX 1)


# 确认一些 变量值：
message(STATUS "[__INFO__] CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "[__INFO__] PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message(STATUS "[__INFO__] CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")



include_directories(include ../ 
../../deps/glm.9.9.5 
../../deps/magic_enum 
../../deps/glad/include 
../../deps/tprGeneral 
../../deps/stb_image 
../../deps/tprInUnix 
../../deps/tprGeneral 
../../deps/rapidjson)


get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> SET DEFAULT TO BEFORE, include_dirs=${dirs}")


add_subdirectory(actionFSM)
add_subdirectory(animFrameSet)
add_subdirectory(actionSwitch)
add_subdirectory(blueprint)
add_subdirectory(camera)
add_subdirectory(circuitBoard)
add_subdirectory(collision)
add_subdirectory(color)
add_subdirectory(coordinate)
add_subdirectory(dataBase)
add_subdirectory(dynamicParam)
add_subdirectory(ecoSys)
add_subdirectory(fileIO)
add_subdirectory(gameObj)
add_subdirectory(gl)
add_subdirectory(input)
add_subdirectory(json)
add_subdirectory(map)
add_subdirectory(mesh)
add_subdirectory(move)
add_subdirectory(multiThread)
add_subdirectory(player)
add_subdirectory(random)
add_subdirectory(renderPool)
add_subdirectory(resource)
add_subdirectory(scene)
add_subdirectory(shaderProgram)
add_subdirectory(sys)
add_subdirectory(time)
add_subdirectory(tools)
add_subdirectory(tprDebug)

add_subdirectory(UI)
add_subdirectory(VAOVBO)

#[[
add_subdirectory(script)
add_subdirectory(affect)
add_subdirectory(AI)
]]



add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/../../deps/glad ${CMAKE_SOURCE_DIR}/../../build/glad)
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/../../deps/tprGeneral ${CMAKE_BINARY_DIR}/../../build/tprgeneral)
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/../../deps/sqlite.3.28 ${CMAKE_BINARY_DIR}/../../build/sqlite)
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/../../deps/fmt-6.1.2 ${CMAKE_BINARY_DIR}/../../build/fmt)
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/../../deps/tprInUnix ${CMAKE_BINARY_DIR}/../../build/lprunix)
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/../../deps/glfw_unix ${CMAKE_BINARY_DIR}/../../build/glfw_unix)





FILE(GLOB_RECURSE PIXEL_FILES   
                        ../Script/*.cpp 
                        )
add_executable (tprpix ${PIXEL_FILES})


#aux_source_directory(. ENGINE_SRCS)
#add_executable (tprpix ${ENGINE_SRCS})


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


## 
