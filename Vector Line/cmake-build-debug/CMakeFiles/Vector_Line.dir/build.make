# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/kruti/Desktop/CG_A1/Vector Line"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/kruti/Desktop/CG_A1/Vector Line/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Vector_Line.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Vector_Line.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vector_Line.dir/flags.make

CMakeFiles/Vector_Line.dir/vector_line.cpp.o: CMakeFiles/Vector_Line.dir/flags.make
CMakeFiles/Vector_Line.dir/vector_line.cpp.o: ../vector_line.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kruti/Desktop/CG_A1/Vector Line/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vector_Line.dir/vector_line.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vector_Line.dir/vector_line.cpp.o -c "/home/kruti/Desktop/CG_A1/Vector Line/vector_line.cpp"

CMakeFiles/Vector_Line.dir/vector_line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vector_Line.dir/vector_line.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kruti/Desktop/CG_A1/Vector Line/vector_line.cpp" > CMakeFiles/Vector_Line.dir/vector_line.cpp.i

CMakeFiles/Vector_Line.dir/vector_line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vector_Line.dir/vector_line.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kruti/Desktop/CG_A1/Vector Line/vector_line.cpp" -o CMakeFiles/Vector_Line.dir/vector_line.cpp.s

# Object files for target Vector_Line
Vector_Line_OBJECTS = \
"CMakeFiles/Vector_Line.dir/vector_line.cpp.o"

# External object files for target Vector_Line
Vector_Line_EXTERNAL_OBJECTS =

Vector_Line: CMakeFiles/Vector_Line.dir/vector_line.cpp.o
Vector_Line: CMakeFiles/Vector_Line.dir/build.make
Vector_Line: CMakeFiles/Vector_Line.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/kruti/Desktop/CG_A1/Vector Line/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Vector_Line"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vector_Line.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vector_Line.dir/build: Vector_Line

.PHONY : CMakeFiles/Vector_Line.dir/build

CMakeFiles/Vector_Line.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vector_Line.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vector_Line.dir/clean

CMakeFiles/Vector_Line.dir/depend:
	cd "/home/kruti/Desktop/CG_A1/Vector Line/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/kruti/Desktop/CG_A1/Vector Line" "/home/kruti/Desktop/CG_A1/Vector Line" "/home/kruti/Desktop/CG_A1/Vector Line/cmake-build-debug" "/home/kruti/Desktop/CG_A1/Vector Line/cmake-build-debug" "/home/kruti/Desktop/CG_A1/Vector Line/cmake-build-debug/CMakeFiles/Vector_Line.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Vector_Line.dir/depend

