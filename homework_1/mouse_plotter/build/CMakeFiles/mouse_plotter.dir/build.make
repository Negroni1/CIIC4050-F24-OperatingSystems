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
CMAKE_SOURCE_DIR = /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/build

# Include any dependencies generated for this target.
include CMakeFiles/mouse_plotter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mouse_plotter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mouse_plotter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mouse_plotter.dir/flags.make

CMakeFiles/mouse_plotter.dir/src/main.c.o: CMakeFiles/mouse_plotter.dir/flags.make
CMakeFiles/mouse_plotter.dir/src/main.c.o: ../src/main.c
CMakeFiles/mouse_plotter.dir/src/main.c.o: CMakeFiles/mouse_plotter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mouse_plotter.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mouse_plotter.dir/src/main.c.o -MF CMakeFiles/mouse_plotter.dir/src/main.c.o.d -o CMakeFiles/mouse_plotter.dir/src/main.c.o -c /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/src/main.c

CMakeFiles/mouse_plotter.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mouse_plotter.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/src/main.c > CMakeFiles/mouse_plotter.dir/src/main.c.i

CMakeFiles/mouse_plotter.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mouse_plotter.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/src/main.c -o CMakeFiles/mouse_plotter.dir/src/main.c.s

# Object files for target mouse_plotter
mouse_plotter_OBJECTS = \
"CMakeFiles/mouse_plotter.dir/src/main.c.o"

# External object files for target mouse_plotter
mouse_plotter_EXTERNAL_OBJECTS =

mouse_plotter: CMakeFiles/mouse_plotter.dir/src/main.c.o
mouse_plotter: CMakeFiles/mouse_plotter.dir/build.make
mouse_plotter: CMakeFiles/mouse_plotter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mouse_plotter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mouse_plotter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mouse_plotter.dir/build: mouse_plotter
.PHONY : CMakeFiles/mouse_plotter.dir/build

CMakeFiles/mouse_plotter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mouse_plotter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mouse_plotter.dir/clean

CMakeFiles/mouse_plotter.dir/depend:
	cd /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/build /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/build /home/morph-ina/Documents/OS/CIIC4050-F24-OperatingSystems/homework_1/mouse_plotter/build/CMakeFiles/mouse_plotter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mouse_plotter.dir/depend

