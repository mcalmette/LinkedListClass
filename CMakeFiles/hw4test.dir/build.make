# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/Desktop/LinkedList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Desktop/LinkedList

# Include any dependencies generated for this target.
include CMakeFiles/hw4test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw4test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw4test.dir/flags.make

CMakeFiles/hw4test.dir/hw4_test.cpp.o: CMakeFiles/hw4test.dir/flags.make
CMakeFiles/hw4test.dir/hw4_test.cpp.o: hw4_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/LinkedList/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw4test.dir/hw4_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw4test.dir/hw4_test.cpp.o -c /home/student/Desktop/LinkedList/hw4_test.cpp

CMakeFiles/hw4test.dir/hw4_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4test.dir/hw4_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/LinkedList/hw4_test.cpp > CMakeFiles/hw4test.dir/hw4_test.cpp.i

CMakeFiles/hw4test.dir/hw4_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4test.dir/hw4_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/LinkedList/hw4_test.cpp -o CMakeFiles/hw4test.dir/hw4_test.cpp.s

# Object files for target hw4test
hw4test_OBJECTS = \
"CMakeFiles/hw4test.dir/hw4_test.cpp.o"

# External object files for target hw4test
hw4test_EXTERNAL_OBJECTS =

hw4test: CMakeFiles/hw4test.dir/hw4_test.cpp.o
hw4test: CMakeFiles/hw4test.dir/build.make
hw4test: /usr/lib/x86_64-linux-gnu/libgtest.a
hw4test: CMakeFiles/hw4test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/Desktop/LinkedList/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw4test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw4test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw4test.dir/build: hw4test

.PHONY : CMakeFiles/hw4test.dir/build

CMakeFiles/hw4test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw4test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw4test.dir/clean

CMakeFiles/hw4test.dir/depend:
	cd /home/student/Desktop/LinkedList && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Desktop/LinkedList /home/student/Desktop/LinkedList /home/student/Desktop/LinkedList /home/student/Desktop/LinkedList /home/student/Desktop/LinkedList/CMakeFiles/hw4test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw4test.dir/depend

