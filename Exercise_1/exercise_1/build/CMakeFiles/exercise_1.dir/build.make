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
CMAKE_SOURCE_DIR = /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/build

# Include any dependencies generated for this target.
include CMakeFiles/exercise_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exercise_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exercise_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise_1.dir/flags.make

CMakeFiles/exercise_1.dir/src/main.c.o: CMakeFiles/exercise_1.dir/flags.make
CMakeFiles/exercise_1.dir/src/main.c.o: /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/src/main.c
CMakeFiles/exercise_1.dir/src/main.c.o: CMakeFiles/exercise_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/exercise_1.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/exercise_1.dir/src/main.c.o -MF CMakeFiles/exercise_1.dir/src/main.c.o.d -o CMakeFiles/exercise_1.dir/src/main.c.o -c /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/src/main.c

CMakeFiles/exercise_1.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/exercise_1.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/src/main.c > CMakeFiles/exercise_1.dir/src/main.c.i

CMakeFiles/exercise_1.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/exercise_1.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/src/main.c -o CMakeFiles/exercise_1.dir/src/main.c.s

# Object files for target exercise_1
exercise_1_OBJECTS = \
"CMakeFiles/exercise_1.dir/src/main.c.o"

# External object files for target exercise_1
exercise_1_EXTERNAL_OBJECTS =

exercise_1: CMakeFiles/exercise_1.dir/src/main.c.o
exercise_1: CMakeFiles/exercise_1.dir/build.make
exercise_1: CMakeFiles/exercise_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable exercise_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exercise_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise_1.dir/build: exercise_1
.PHONY : CMakeFiles/exercise_1.dir/build

CMakeFiles/exercise_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exercise_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exercise_1.dir/clean

CMakeFiles/exercise_1.dir/depend:
	cd /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1 /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1 /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/build /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/build /Users/negroni/Documents/F24/OS/Lab2/Exercise_1/exercise_1/build/CMakeFiles/exercise_1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/exercise_1.dir/depend

