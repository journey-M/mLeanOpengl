cmake_minimum_required(VERSION 3.2.0)

SET(CMAKE_BUILE_TYPE DEBUG)
add_definitions("-Wall -g -static")

ADD_SUBDIRECTORY(json11-master)
ADD_SUBDIRECTORY(tinygltf)


