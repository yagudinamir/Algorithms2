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
CMAKE_SOURCE_DIR = "/Users/amir/CLionProjects/Edmands Karp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/amir/CLionProjects/Edmands Karp/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Edmands_Karp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Edmands_Karp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Edmands_Karp.dir/flags.make

CMakeFiles/Edmands_Karp.dir/main.cpp.o: CMakeFiles/Edmands_Karp.dir/flags.make
CMakeFiles/Edmands_Karp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/amir/CLionProjects/Edmands Karp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Edmands_Karp.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Edmands_Karp.dir/main.cpp.o -c "/Users/amir/CLionProjects/Edmands Karp/main.cpp"

CMakeFiles/Edmands_Karp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Edmands_Karp.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/amir/CLionProjects/Edmands Karp/main.cpp" > CMakeFiles/Edmands_Karp.dir/main.cpp.i

CMakeFiles/Edmands_Karp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Edmands_Karp.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/amir/CLionProjects/Edmands Karp/main.cpp" -o CMakeFiles/Edmands_Karp.dir/main.cpp.s

CMakeFiles/Edmands_Karp.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Edmands_Karp.dir/main.cpp.o.requires

CMakeFiles/Edmands_Karp.dir/main.cpp.o.provides: CMakeFiles/Edmands_Karp.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Edmands_Karp.dir/build.make CMakeFiles/Edmands_Karp.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Edmands_Karp.dir/main.cpp.o.provides

CMakeFiles/Edmands_Karp.dir/main.cpp.o.provides.build: CMakeFiles/Edmands_Karp.dir/main.cpp.o


# Object files for target Edmands_Karp
Edmands_Karp_OBJECTS = \
"CMakeFiles/Edmands_Karp.dir/main.cpp.o"

# External object files for target Edmands_Karp
Edmands_Karp_EXTERNAL_OBJECTS =

Edmands_Karp: CMakeFiles/Edmands_Karp.dir/main.cpp.o
Edmands_Karp: CMakeFiles/Edmands_Karp.dir/build.make
Edmands_Karp: CMakeFiles/Edmands_Karp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/amir/CLionProjects/Edmands Karp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Edmands_Karp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Edmands_Karp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Edmands_Karp.dir/build: Edmands_Karp

.PHONY : CMakeFiles/Edmands_Karp.dir/build

CMakeFiles/Edmands_Karp.dir/requires: CMakeFiles/Edmands_Karp.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Edmands_Karp.dir/requires

CMakeFiles/Edmands_Karp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Edmands_Karp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Edmands_Karp.dir/clean

CMakeFiles/Edmands_Karp.dir/depend:
	cd "/Users/amir/CLionProjects/Edmands Karp/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/amir/CLionProjects/Edmands Karp" "/Users/amir/CLionProjects/Edmands Karp" "/Users/amir/CLionProjects/Edmands Karp/cmake-build-debug" "/Users/amir/CLionProjects/Edmands Karp/cmake-build-debug" "/Users/amir/CLionProjects/Edmands Karp/cmake-build-debug/CMakeFiles/Edmands_Karp.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Edmands_Karp.dir/depend

