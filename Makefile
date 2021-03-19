# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guoweijie004/workspaces/opengl-project/mopengl-test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guoweijie004/workspaces/opengl-project/mopengl-test

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/guoweijie004/workspaces/opengl-project/mopengl-test/CMakeFiles /home/guoweijie004/workspaces/opengl-project/mopengl-test//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/guoweijie004/workspaces/opengl-project/mopengl-test/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

#=============================================================================
# Target rules for targets named sublib

# Build rule for target.
sublib: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 sublib
.PHONY : sublib

# fast build rule for target.
sublib/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/build
.PHONY : sublib/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

src/Camera.o: src/Camera.cpp.o

.PHONY : src/Camera.o

# target to build an object file
src/Camera.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Camera.cpp.o
.PHONY : src/Camera.cpp.o

src/Camera.i: src/Camera.cpp.i

.PHONY : src/Camera.i

# target to preprocess a source file
src/Camera.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Camera.cpp.i
.PHONY : src/Camera.cpp.i

src/Camera.s: src/Camera.cpp.s

.PHONY : src/Camera.s

# target to generate assembly for a file
src/Camera.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Camera.cpp.s
.PHONY : src/Camera.cpp.s

src/CameraMouse.o: src/CameraMouse.cpp.o

.PHONY : src/CameraMouse.o

# target to build an object file
src/CameraMouse.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CameraMouse.cpp.o
.PHONY : src/CameraMouse.cpp.o

src/CameraMouse.i: src/CameraMouse.cpp.i

.PHONY : src/CameraMouse.i

# target to preprocess a source file
src/CameraMouse.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CameraMouse.cpp.i
.PHONY : src/CameraMouse.cpp.i

src/CameraMouse.s: src/CameraMouse.cpp.s

.PHONY : src/CameraMouse.s

# target to generate assembly for a file
src/CameraMouse.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CameraMouse.cpp.s
.PHONY : src/CameraMouse.cpp.s

src/CameraMove.o: src/CameraMove.cpp.o

.PHONY : src/CameraMove.o

# target to build an object file
src/CameraMove.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CameraMove.cpp.o
.PHONY : src/CameraMove.cpp.o

src/CameraMove.i: src/CameraMove.cpp.i

.PHONY : src/CameraMove.i

# target to preprocess a source file
src/CameraMove.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CameraMove.cpp.i
.PHONY : src/CameraMove.cpp.i

src/CameraMove.s: src/CameraMove.cpp.s

.PHONY : src/CameraMove.s

# target to generate assembly for a file
src/CameraMove.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CameraMove.cpp.s
.PHONY : src/CameraMove.cpp.s

src/Coordinate.o: src/Coordinate.cpp.o

.PHONY : src/Coordinate.o

# target to build an object file
src/Coordinate.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Coordinate.cpp.o
.PHONY : src/Coordinate.cpp.o

src/Coordinate.i: src/Coordinate.cpp.i

.PHONY : src/Coordinate.i

# target to preprocess a source file
src/Coordinate.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Coordinate.cpp.i
.PHONY : src/Coordinate.cpp.i

src/Coordinate.s: src/Coordinate.cpp.s

.PHONY : src/Coordinate.s

# target to generate assembly for a file
src/Coordinate.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Coordinate.cpp.s
.PHONY : src/Coordinate.cpp.s

src/CoordinateCube.o: src/CoordinateCube.cpp.o

.PHONY : src/CoordinateCube.o

# target to build an object file
src/CoordinateCube.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CoordinateCube.cpp.o
.PHONY : src/CoordinateCube.cpp.o

src/CoordinateCube.i: src/CoordinateCube.cpp.i

.PHONY : src/CoordinateCube.i

# target to preprocess a source file
src/CoordinateCube.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CoordinateCube.cpp.i
.PHONY : src/CoordinateCube.cpp.i

src/CoordinateCube.s: src/CoordinateCube.cpp.s

.PHONY : src/CoordinateCube.s

# target to generate assembly for a file
src/CoordinateCube.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CoordinateCube.cpp.s
.PHONY : src/CoordinateCube.cpp.s

src/CoordinateCubes_More.o: src/CoordinateCubes_More.cpp.o

.PHONY : src/CoordinateCubes_More.o

# target to build an object file
src/CoordinateCubes_More.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CoordinateCubes_More.cpp.o
.PHONY : src/CoordinateCubes_More.cpp.o

src/CoordinateCubes_More.i: src/CoordinateCubes_More.cpp.i

.PHONY : src/CoordinateCubes_More.i

# target to preprocess a source file
src/CoordinateCubes_More.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CoordinateCubes_More.cpp.i
.PHONY : src/CoordinateCubes_More.cpp.i

src/CoordinateCubes_More.s: src/CoordinateCubes_More.cpp.s

.PHONY : src/CoordinateCubes_More.s

# target to generate assembly for a file
src/CoordinateCubes_More.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/CoordinateCubes_More.cpp.s
.PHONY : src/CoordinateCubes_More.cpp.s

src/IOperator.o: src/IOperator.cpp.o

.PHONY : src/IOperator.o

# target to build an object file
src/IOperator.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/IOperator.cpp.o
.PHONY : src/IOperator.cpp.o

src/IOperator.i: src/IOperator.cpp.i

.PHONY : src/IOperator.i

# target to preprocess a source file
src/IOperator.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/IOperator.cpp.i
.PHONY : src/IOperator.cpp.i

src/IOperator.s: src/IOperator.cpp.s

.PHONY : src/IOperator.s

# target to generate assembly for a file
src/IOperator.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/IOperator.cpp.s
.PHONY : src/IOperator.cpp.s

src/LeanShader.o: src/LeanShader.cpp.o

.PHONY : src/LeanShader.o

# target to build an object file
src/LeanShader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/LeanShader.cpp.o
.PHONY : src/LeanShader.cpp.o

src/LeanShader.i: src/LeanShader.cpp.i

.PHONY : src/LeanShader.i

# target to preprocess a source file
src/LeanShader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/LeanShader.cpp.i
.PHONY : src/LeanShader.cpp.i

src/LeanShader.s: src/LeanShader.cpp.s

.PHONY : src/LeanShader.s

# target to generate assembly for a file
src/LeanShader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/LeanShader.cpp.s
.PHONY : src/LeanShader.cpp.s

src/Shader.o: src/Shader.cpp.o

.PHONY : src/Shader.o

# target to build an object file
src/Shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Shader.cpp.o
.PHONY : src/Shader.cpp.o

src/Shader.i: src/Shader.cpp.i

.PHONY : src/Shader.i

# target to preprocess a source file
src/Shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Shader.cpp.i
.PHONY : src/Shader.cpp.i

src/Shader.s: src/Shader.cpp.s

.PHONY : src/Shader.s

# target to generate assembly for a file
src/Shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Shader.cpp.s
.PHONY : src/Shader.cpp.s

src/Square.o: src/Square.cpp.o

.PHONY : src/Square.o

# target to build an object file
src/Square.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Square.cpp.o
.PHONY : src/Square.cpp.o

src/Square.i: src/Square.cpp.i

.PHONY : src/Square.i

# target to preprocess a source file
src/Square.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Square.cpp.i
.PHONY : src/Square.cpp.i

src/Square.s: src/Square.cpp.s

.PHONY : src/Square.s

# target to generate assembly for a file
src/Square.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Square.cpp.s
.PHONY : src/Square.cpp.s

src/TestFileShader.o: src/TestFileShader.cpp.o

.PHONY : src/TestFileShader.o

# target to build an object file
src/TestFileShader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/TestFileShader.cpp.o
.PHONY : src/TestFileShader.cpp.o

src/TestFileShader.i: src/TestFileShader.cpp.i

.PHONY : src/TestFileShader.i

# target to preprocess a source file
src/TestFileShader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/TestFileShader.cpp.i
.PHONY : src/TestFileShader.cpp.i

src/TestFileShader.s: src/TestFileShader.cpp.s

.PHONY : src/TestFileShader.s

# target to generate assembly for a file
src/TestFileShader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/TestFileShader.cpp.s
.PHONY : src/TestFileShader.cpp.s

src/Texture.o: src/Texture.cpp.o

.PHONY : src/Texture.o

# target to build an object file
src/Texture.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Texture.cpp.o
.PHONY : src/Texture.cpp.o

src/Texture.i: src/Texture.cpp.i

.PHONY : src/Texture.i

# target to preprocess a source file
src/Texture.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Texture.cpp.i
.PHONY : src/Texture.cpp.i

src/Texture.s: src/Texture.cpp.s

.PHONY : src/Texture.s

# target to generate assembly for a file
src/Texture.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Texture.cpp.s
.PHONY : src/Texture.cpp.s

src/Texture2.o: src/Texture2.cpp.o

.PHONY : src/Texture2.o

# target to build an object file
src/Texture2.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Texture2.cpp.o
.PHONY : src/Texture2.cpp.o

src/Texture2.i: src/Texture2.cpp.i

.PHONY : src/Texture2.i

# target to preprocess a source file
src/Texture2.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Texture2.cpp.i
.PHONY : src/Texture2.cpp.i

src/Texture2.s: src/Texture2.cpp.s

.PHONY : src/Texture2.s

# target to generate assembly for a file
src/Texture2.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Texture2.cpp.s
.PHONY : src/Texture2.cpp.s

src/Transformations.o: src/Transformations.cpp.o

.PHONY : src/Transformations.o

# target to build an object file
src/Transformations.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Transformations.cpp.o
.PHONY : src/Transformations.cpp.o

src/Transformations.i: src/Transformations.cpp.i

.PHONY : src/Transformations.i

# target to preprocess a source file
src/Transformations.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Transformations.cpp.i
.PHONY : src/Transformations.cpp.i

src/Transformations.s: src/Transformations.cpp.s

.PHONY : src/Transformations.s

# target to generate assembly for a file
src/Transformations.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Transformations.cpp.s
.PHONY : src/Transformations.cpp.s

src/Trigle.o: src/Trigle.cpp.o

.PHONY : src/Trigle.o

# target to build an object file
src/Trigle.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Trigle.cpp.o
.PHONY : src/Trigle.cpp.o

src/Trigle.i: src/Trigle.cpp.i

.PHONY : src/Trigle.i

# target to preprocess a source file
src/Trigle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Trigle.cpp.i
.PHONY : src/Trigle.cpp.i

src/Trigle.s: src/Trigle.cpp.s

.PHONY : src/Trigle.s

# target to generate assembly for a file
src/Trigle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/Trigle.cpp.s
.PHONY : src/Trigle.cpp.s

src/glad.o: src/glad.c.o

.PHONY : src/glad.o

# target to build an object file
src/glad.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/glad.c.o
.PHONY : src/glad.c.o

src/glad.i: src/glad.c.i

.PHONY : src/glad.i

# target to preprocess a source file
src/glad.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/glad.c.i
.PHONY : src/glad.c.i

src/glad.s: src/glad.c.s

.PHONY : src/glad.s

# target to generate assembly for a file
src/glad.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/glad.c.s
.PHONY : src/glad.c.s

src/std_image.o: src/std_image.cpp.o

.PHONY : src/std_image.o

# target to build an object file
src/std_image.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/std_image.cpp.o
.PHONY : src/std_image.cpp.o

src/std_image.i: src/std_image.cpp.i

.PHONY : src/std_image.i

# target to preprocess a source file
src/std_image.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/std_image.cpp.i
.PHONY : src/std_image.cpp.i

src/std_image.s: src/std_image.cpp.s

.PHONY : src/std_image.s

# target to generate assembly for a file
src/std_image.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sublib.dir/build.make CMakeFiles/sublib.dir/src/std_image.cpp.s
.PHONY : src/std_image.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... main"
	@echo "... sublib"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/Camera.o"
	@echo "... src/Camera.i"
	@echo "... src/Camera.s"
	@echo "... src/CameraMouse.o"
	@echo "... src/CameraMouse.i"
	@echo "... src/CameraMouse.s"
	@echo "... src/CameraMove.o"
	@echo "... src/CameraMove.i"
	@echo "... src/CameraMove.s"
	@echo "... src/Coordinate.o"
	@echo "... src/Coordinate.i"
	@echo "... src/Coordinate.s"
	@echo "... src/CoordinateCube.o"
	@echo "... src/CoordinateCube.i"
	@echo "... src/CoordinateCube.s"
	@echo "... src/CoordinateCubes_More.o"
	@echo "... src/CoordinateCubes_More.i"
	@echo "... src/CoordinateCubes_More.s"
	@echo "... src/IOperator.o"
	@echo "... src/IOperator.i"
	@echo "... src/IOperator.s"
	@echo "... src/LeanShader.o"
	@echo "... src/LeanShader.i"
	@echo "... src/LeanShader.s"
	@echo "... src/Shader.o"
	@echo "... src/Shader.i"
	@echo "... src/Shader.s"
	@echo "... src/Square.o"
	@echo "... src/Square.i"
	@echo "... src/Square.s"
	@echo "... src/TestFileShader.o"
	@echo "... src/TestFileShader.i"
	@echo "... src/TestFileShader.s"
	@echo "... src/Texture.o"
	@echo "... src/Texture.i"
	@echo "... src/Texture.s"
	@echo "... src/Texture2.o"
	@echo "... src/Texture2.i"
	@echo "... src/Texture2.s"
	@echo "... src/Transformations.o"
	@echo "... src/Transformations.i"
	@echo "... src/Transformations.s"
	@echo "... src/Trigle.o"
	@echo "... src/Trigle.i"
	@echo "... src/Trigle.s"
	@echo "... src/glad.o"
	@echo "... src/glad.i"
	@echo "... src/glad.s"
	@echo "... src/std_image.o"
	@echo "... src/std_image.i"
	@echo "... src/std_image.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

