project(luacpp) 
cmake_minimum_required( VERSION 2.8 )

aux_source_directory(cpp2lua SRCS_CPP2LUA)
add_executable(cpp2l ${SRCS_CPP2LUA})
target_link_libraries(cpp2l -llua ) # exe 链接 OpenCV_INCLUDE_DIRS


aux_source_directory(lua2cpp srcs_lua2cpp)
add_executable(l2cpp ${srcs_lua2cpp})
target_link_libraries( l2cpp -llua ) # exe 链接 opencv
