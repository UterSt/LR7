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
CMAKE_SOURCE_DIR = /home/user/Documents/453501/ОАиП/LR7/Tasks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Documents/453501/ОАиП/LR7/Tasks/build

# Include any dependencies generated for this target.
include CMakeFiles/main_Asan.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_Asan.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_Asan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_Asan.dir/flags.make

CMakeFiles/main_Asan.dir/Tasks.cpp.o: CMakeFiles/main_Asan.dir/flags.make
CMakeFiles/main_Asan.dir/Tasks.cpp.o: ../Tasks.cpp
CMakeFiles/main_Asan.dir/Tasks.cpp.o: CMakeFiles/main_Asan.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/453501/ОАиП/LR7/Tasks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_Asan.dir/Tasks.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_Asan.dir/Tasks.cpp.o -MF CMakeFiles/main_Asan.dir/Tasks.cpp.o.d -o CMakeFiles/main_Asan.dir/Tasks.cpp.o -c /home/user/Documents/453501/ОАиП/LR7/Tasks/Tasks.cpp

CMakeFiles/main_Asan.dir/Tasks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_Asan.dir/Tasks.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/453501/ОАиП/LR7/Tasks/Tasks.cpp > CMakeFiles/main_Asan.dir/Tasks.cpp.i

CMakeFiles/main_Asan.dir/Tasks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_Asan.dir/Tasks.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/453501/ОАиП/LR7/Tasks/Tasks.cpp -o CMakeFiles/main_Asan.dir/Tasks.cpp.s

# Object files for target main_Asan
main_Asan_OBJECTS = \
"CMakeFiles/main_Asan.dir/Tasks.cpp.o"

# External object files for target main_Asan
main_Asan_EXTERNAL_OBJECTS =

main_Asan: CMakeFiles/main_Asan.dir/Tasks.cpp.o
main_Asan: CMakeFiles/main_Asan.dir/build.make
main_Asan: libString.a
main_Asan: CMakeFiles/main_Asan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Documents/453501/ОАиП/LR7/Tasks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main_Asan"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_Asan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_Asan.dir/build: main_Asan
.PHONY : CMakeFiles/main_Asan.dir/build

CMakeFiles/main_Asan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_Asan.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_Asan.dir/clean

CMakeFiles/main_Asan.dir/depend:
	cd /home/user/Documents/453501/ОАиП/LR7/Tasks/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Documents/453501/ОАиП/LR7/Tasks /home/user/Documents/453501/ОАиП/LR7/Tasks /home/user/Documents/453501/ОАиП/LR7/Tasks/build /home/user/Documents/453501/ОАиП/LR7/Tasks/build /home/user/Documents/453501/ОАиП/LR7/Tasks/build/CMakeFiles/main_Asan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_Asan.dir/depend
