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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/viktoria/Documents/OOP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/viktoria/Documents/OOP/build

# Include any dependencies generated for this target.
include googletest-buid/googletest/CMakeFiles/gtest_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include googletest-buid/googletest/CMakeFiles/gtest_main.dir/compiler_depend.make

# Include the progress variables for this target.
include googletest-buid/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include googletest-buid/googletest/CMakeFiles/gtest_main.dir/flags.make

googletest-buid/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: googletest-buid/googletest/CMakeFiles/gtest_main.dir/flags.make
googletest-buid/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: /Users/viktoria/Documents/OOP/lib/googletest/googletest/src/gtest_main.cc
googletest-buid/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: googletest-buid/googletest/CMakeFiles/gtest_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/viktoria/Documents/OOP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest-buid/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /Users/viktoria/Documents/OOP/build/googletest-buid/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT googletest-buid/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -MF CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.d -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /Users/viktoria/Documents/OOP/lib/googletest/googletest/src/gtest_main.cc

googletest-buid/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /Users/viktoria/Documents/OOP/build/googletest-buid/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/viktoria/Documents/OOP/lib/googletest/googletest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

googletest-buid/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /Users/viktoria/Documents/OOP/build/googletest-buid/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/viktoria/Documents/OOP/lib/googletest/googletest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

lib/libgtest_main.a: googletest-buid/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
lib/libgtest_main.a: googletest-buid/googletest/CMakeFiles/gtest_main.dir/build.make
lib/libgtest_main.a: googletest-buid/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/viktoria/Documents/OOP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libgtest_main.a"
	cd /Users/viktoria/Documents/OOP/build/googletest-buid/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /Users/viktoria/Documents/OOP/build/googletest-buid/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest-buid/googletest/CMakeFiles/gtest_main.dir/build: lib/libgtest_main.a
.PHONY : googletest-buid/googletest/CMakeFiles/gtest_main.dir/build

googletest-buid/googletest/CMakeFiles/gtest_main.dir/clean:
	cd /Users/viktoria/Documents/OOP/build/googletest-buid/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : googletest-buid/googletest/CMakeFiles/gtest_main.dir/clean

googletest-buid/googletest/CMakeFiles/gtest_main.dir/depend:
	cd /Users/viktoria/Documents/OOP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/viktoria/Documents/OOP /Users/viktoria/Documents/OOP/lib/googletest/googletest /Users/viktoria/Documents/OOP/build /Users/viktoria/Documents/OOP/build/googletest-buid/googletest /Users/viktoria/Documents/OOP/build/googletest-buid/googletest/CMakeFiles/gtest_main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : googletest-buid/googletest/CMakeFiles/gtest_main.dir/depend

