# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/amir/CLionProjects/PrimeNumbersGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amir/CLionProjects/PrimeNumbersGame/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PrimeNumbersGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PrimeNumbersGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PrimeNumbersGame.dir/flags.make

CMakeFiles/PrimeNumbersGame.dir/main.cpp.o: CMakeFiles/PrimeNumbersGame.dir/flags.make
CMakeFiles/PrimeNumbersGame.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amir/CLionProjects/PrimeNumbersGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PrimeNumbersGame.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PrimeNumbersGame.dir/main.cpp.o -c /Users/amir/CLionProjects/PrimeNumbersGame/main.cpp

CMakeFiles/PrimeNumbersGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PrimeNumbersGame.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amir/CLionProjects/PrimeNumbersGame/main.cpp > CMakeFiles/PrimeNumbersGame.dir/main.cpp.i

CMakeFiles/PrimeNumbersGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PrimeNumbersGame.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amir/CLionProjects/PrimeNumbersGame/main.cpp -o CMakeFiles/PrimeNumbersGame.dir/main.cpp.s

CMakeFiles/PrimeNumbersGame.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PrimeNumbersGame.dir/main.cpp.o.requires

CMakeFiles/PrimeNumbersGame.dir/main.cpp.o.provides: CMakeFiles/PrimeNumbersGame.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PrimeNumbersGame.dir/build.make CMakeFiles/PrimeNumbersGame.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PrimeNumbersGame.dir/main.cpp.o.provides

CMakeFiles/PrimeNumbersGame.dir/main.cpp.o.provides.build: CMakeFiles/PrimeNumbersGame.dir/main.cpp.o


# Object files for target PrimeNumbersGame
PrimeNumbersGame_OBJECTS = \
"CMakeFiles/PrimeNumbersGame.dir/main.cpp.o"

# External object files for target PrimeNumbersGame
PrimeNumbersGame_EXTERNAL_OBJECTS =

PrimeNumbersGame: CMakeFiles/PrimeNumbersGame.dir/main.cpp.o
PrimeNumbersGame: CMakeFiles/PrimeNumbersGame.dir/build.make
PrimeNumbersGame: CMakeFiles/PrimeNumbersGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/amir/CLionProjects/PrimeNumbersGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PrimeNumbersGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PrimeNumbersGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PrimeNumbersGame.dir/build: PrimeNumbersGame

.PHONY : CMakeFiles/PrimeNumbersGame.dir/build

CMakeFiles/PrimeNumbersGame.dir/requires: CMakeFiles/PrimeNumbersGame.dir/main.cpp.o.requires

.PHONY : CMakeFiles/PrimeNumbersGame.dir/requires

CMakeFiles/PrimeNumbersGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PrimeNumbersGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PrimeNumbersGame.dir/clean

CMakeFiles/PrimeNumbersGame.dir/depend:
	cd /Users/amir/CLionProjects/PrimeNumbersGame/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amir/CLionProjects/PrimeNumbersGame /Users/amir/CLionProjects/PrimeNumbersGame /Users/amir/CLionProjects/PrimeNumbersGame/cmake-build-debug /Users/amir/CLionProjects/PrimeNumbersGame/cmake-build-debug /Users/amir/CLionProjects/PrimeNumbersGame/cmake-build-debug/CMakeFiles/PrimeNumbersGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PrimeNumbersGame.dir/depend

