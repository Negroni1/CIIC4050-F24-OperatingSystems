# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/build

# Include any dependencies generated for this target.
include CMakeFiles/children.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/children.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/children.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/children.dir/flags.make

CMakeFiles/children.dir/src/main.c.o: CMakeFiles/children.dir/flags.make
CMakeFiles/children.dir/src/main.c.o: /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/src/main.c
CMakeFiles/children.dir/src/main.c.o: CMakeFiles/children.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/children.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/children.dir/src/main.c.o -MF CMakeFiles/children.dir/src/main.c.o.d -o CMakeFiles/children.dir/src/main.c.o -c /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/src/main.c

CMakeFiles/children.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/children.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/src/main.c > CMakeFiles/children.dir/src/main.c.i

CMakeFiles/children.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/children.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/src/main.c -o CMakeFiles/children.dir/src/main.c.s

# Object files for target children
children_OBJECTS = \
"CMakeFiles/children.dir/src/main.c.o"

# External object files for target children
children_EXTERNAL_OBJECTS =

children: CMakeFiles/children.dir/src/main.c.o
children: CMakeFiles/children.dir/build.make
children: CMakeFiles/children.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable children"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/children.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/children.dir/build: children
.PHONY : CMakeFiles/children.dir/build

CMakeFiles/children.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/children.dir/cmake_clean.cmake
.PHONY : CMakeFiles/children.dir/clean

CMakeFiles/children.dir/depend:
	cd /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/build /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/build /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/child/build/CMakeFiles/children.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/children.dir/depend

