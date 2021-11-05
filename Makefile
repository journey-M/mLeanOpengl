# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/gwj/workspaces/TowerDefends

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gwj/workspaces/TowerDefends

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

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
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gwj/workspaces/TowerDefends/CMakeFiles /home/gwj/workspaces/TowerDefends//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gwj/workspaces/TowerDefends/CMakeFiles 0
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
# Target rules for targets named TowerDefends

# Build rule for target.
TowerDefends: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 TowerDefends
.PHONY : TowerDefends

# fast build rule for target.
TowerDefends/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefends.dir/build.make CMakeFiles/TowerDefends.dir/build
.PHONY : TowerDefends/fast

#=============================================================================
# Target rules for targets named engin

# Build rule for target.
engin: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 engin
.PHONY : engin

# fast build rule for target.
engin/fast:
	$(MAKE) $(MAKESILENT) -f engin/CMakeFiles/engin.dir/build.make engin/CMakeFiles/engin.dir/build
.PHONY : engin/fast

#=============================================================================
# Target rules for targets named gl40

# Build rule for target.
gl40: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gl40
.PHONY : gl40

# fast build rule for target.
gl40/fast:
	$(MAKE) $(MAKESILENT) -f engin/graphic_glsl4.0/CMakeFiles/gl40.dir/build.make engin/graphic_glsl4.0/CMakeFiles/gl40.dir/build
.PHONY : gl40/fast

#=============================================================================
# Target rules for targets named json11

# Build rule for target.
json11: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 json11
.PHONY : json11

# fast build rule for target.
json11/fast:
	$(MAKE) $(MAKESILENT) -f engin/third-libs/json11-master/CMakeFiles/json11.dir/build.make engin/third-libs/json11-master/CMakeFiles/json11.dir/build
.PHONY : json11/fast

#=============================================================================
# Target rules for targets named tinygltf

# Build rule for target.
tinygltf: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 tinygltf
.PHONY : tinygltf

# fast build rule for target.
tinygltf/fast:
	$(MAKE) $(MAKESILENT) -f engin/third-libs/tinygltf/CMakeFiles/tinygltf.dir/build.make engin/third-libs/tinygltf/CMakeFiles/tinygltf.dir/build
.PHONY : tinygltf/fast

#=============================================================================
# Target rules for targets named loader_example

# Build rule for target.
loader_example: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 loader_example
.PHONY : loader_example

# fast build rule for target.
loader_example/fast:
	$(MAKE) $(MAKESILENT) -f engin/third-libs/tinygltf/CMakeFiles/loader_example.dir/build.make engin/third-libs/tinygltf/CMakeFiles/loader_example.dir/build
.PHONY : loader_example/fast

logic/run.o: logic/run.cpp.o
.PHONY : logic/run.o

# target to build an object file
logic/run.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefends.dir/build.make CMakeFiles/TowerDefends.dir/logic/run.cpp.o
.PHONY : logic/run.cpp.o

logic/run.i: logic/run.cpp.i
.PHONY : logic/run.i

# target to preprocess a source file
logic/run.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefends.dir/build.make CMakeFiles/TowerDefends.dir/logic/run.cpp.i
.PHONY : logic/run.cpp.i

logic/run.s: logic/run.cpp.s
.PHONY : logic/run.s

# target to generate assembly for a file
logic/run.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefends.dir/build.make CMakeFiles/TowerDefends.dir/logic/run.cpp.s
.PHONY : logic/run.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... TowerDefends"
	@echo "... engin"
	@echo "... gl40"
	@echo "... json11"
	@echo "... loader_example"
	@echo "... tinygltf"
	@echo "... logic/run.o"
	@echo "... logic/run.i"
	@echo "... logic/run.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

