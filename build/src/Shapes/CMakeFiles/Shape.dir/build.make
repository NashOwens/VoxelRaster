# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_SOURCE_DIR = /home/nash/git/graph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nash/git/graph/build

# Include any dependencies generated for this target.
include src/Shapes/CMakeFiles/Shape.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Shapes/CMakeFiles/Shape.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Shapes/CMakeFiles/Shape.dir/progress.make

# Include the compile flags for this target's objects.
include src/Shapes/CMakeFiles/Shape.dir/flags.make

src/Shapes/CMakeFiles/Shape.dir/Shape.cpp.o: src/Shapes/CMakeFiles/Shape.dir/flags.make
src/Shapes/CMakeFiles/Shape.dir/Shape.cpp.o: ../src/Shapes/Shape.cpp
src/Shapes/CMakeFiles/Shape.dir/Shape.cpp.o: src/Shapes/CMakeFiles/Shape.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nash/git/graph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Shapes/CMakeFiles/Shape.dir/Shape.cpp.o"
	cd /home/nash/git/graph/build/src/Shapes && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Shapes/CMakeFiles/Shape.dir/Shape.cpp.o -MF CMakeFiles/Shape.dir/Shape.cpp.o.d -o CMakeFiles/Shape.dir/Shape.cpp.o -c /home/nash/git/graph/src/Shapes/Shape.cpp

src/Shapes/CMakeFiles/Shape.dir/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shape.dir/Shape.cpp.i"
	cd /home/nash/git/graph/build/src/Shapes && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nash/git/graph/src/Shapes/Shape.cpp > CMakeFiles/Shape.dir/Shape.cpp.i

src/Shapes/CMakeFiles/Shape.dir/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shape.dir/Shape.cpp.s"
	cd /home/nash/git/graph/build/src/Shapes && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nash/git/graph/src/Shapes/Shape.cpp -o CMakeFiles/Shape.dir/Shape.cpp.s

# Object files for target Shape
Shape_OBJECTS = \
"CMakeFiles/Shape.dir/Shape.cpp.o"

# External object files for target Shape
Shape_EXTERNAL_OBJECTS =

src/Shapes/libShape.a: src/Shapes/CMakeFiles/Shape.dir/Shape.cpp.o
src/Shapes/libShape.a: src/Shapes/CMakeFiles/Shape.dir/build.make
src/Shapes/libShape.a: src/Shapes/CMakeFiles/Shape.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nash/git/graph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libShape.a"
	cd /home/nash/git/graph/build/src/Shapes && $(CMAKE_COMMAND) -P CMakeFiles/Shape.dir/cmake_clean_target.cmake
	cd /home/nash/git/graph/build/src/Shapes && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Shape.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Shapes/CMakeFiles/Shape.dir/build: src/Shapes/libShape.a
.PHONY : src/Shapes/CMakeFiles/Shape.dir/build

src/Shapes/CMakeFiles/Shape.dir/clean:
	cd /home/nash/git/graph/build/src/Shapes && $(CMAKE_COMMAND) -P CMakeFiles/Shape.dir/cmake_clean.cmake
.PHONY : src/Shapes/CMakeFiles/Shape.dir/clean

src/Shapes/CMakeFiles/Shape.dir/depend:
	cd /home/nash/git/graph/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nash/git/graph /home/nash/git/graph/src/Shapes /home/nash/git/graph/build /home/nash/git/graph/build/src/Shapes /home/nash/git/graph/build/src/Shapes/CMakeFiles/Shape.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Shapes/CMakeFiles/Shape.dir/depend

