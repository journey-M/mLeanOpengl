
project(trip)

cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)





# 确认一些 变量值：
message(STATUS "[__INFO__] CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "[__INFO__] PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message(STATUS "[__INFO__] CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


aux_source_directory(. ENGINE_SRCS)

add_subdirectory(actionFSM)
add_subdirectory(animFrameSet)
add_subdirectory(actionSwitch)
add_subdirectory(blueprint)
add_subdirectory(camera)


#[[
add_subdirectory(collision)
add_subdirectory(dynamicParam)
add_subdirectory(gl)
add_subdirectory(mesh)
add_subdirectory(random)
add_subdirectory(script)
add_subdirectory(tools)
add_subdirectory(color)
add_subdirectory(ecoSys)
add_subdirectory(input)
add_subdirectory(move)
add_subdirectory(renderPool)
add_subdirectory(shaderProgram)
add_subdirectory(tprDebug)
add_subdirectory(affect)
add_subdirectory(coordinate)
add_subdirectory(fileIO)
add_subdirectory(json)
add_subdirectory(multiThread)
add_subdirectory(resource)
add_subdirectory(sys)
add_subdirectory(UI)
add_subdirectory(AI)
add_subdirectory(circuitBoard)
add_subdirectory(dataBase)
add_subdirectory(gameObj)
add_subdirectory(map)
add_subdirectory(player)
add_subdirectory(scene)
add_subdirectory(time)
add_subdirectory(VAOVBO)

]]

add_library (engine ${ENGINE_SRCS})
target_link_libraries(engine PUBLIC engine_actionfsm  engine_actionswitch  engine_animframset engine_blueprint engine_camera)
