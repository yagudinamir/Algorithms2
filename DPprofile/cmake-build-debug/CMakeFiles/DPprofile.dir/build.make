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
CMAKE_SOURCE_DIR = /Users/amir/CLionProjects/DPprofile

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amir/CLionProjects/DPprofile/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DPprofile.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DPprofile.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DPprofile.dir/flags.make

CMakeFiles/DPprofile.dir/main.cpp.o: CMakeFiles/DPprofile.dir/flags.make
CMakeFiles/DPprofile.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amir/CLionProjects/DPprofile/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DPprofile.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DPprofile.dir/main.cpp.o -c /Users/amir/CLionProjects/DPprofile/main.cpp

CMakeFiles/DPprofile.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DPprofile.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amir/CLionProjects/DPprofile/main.cpp > CMakeFiles/DPprofile.dir/main.cpp.i

CMakeFiles/DPprofile.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DPprofile.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amir/CLionProjects/DPprofile/main.cpp -o CMakeFiles/DPprofile.dir/main.cpp.s

CMakeFiles/DPprofile.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DPprofile.dir/main.cpp.o.requires

CMakeFiles/DPprofile.dir/main.cpp.o.provides: CMakeFiles/DPprofile.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DPprofile.dir/build.make CMakeFiles/DPprofile.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DPprofile.dir/main.cpp.o.provides

CMakeFiles/DPprofile.dir/main.cpp.o.provides.build: CMakeFiles/DPprofile.dir/main.cpp.o


# Object files for target DPprofile
DPprofile_OBJECTS = \
"CMakeFiles/DPprofile.dir/main.cpp.o"

# External object files for target DPprofile
DPprofile_EXTERNAL_OBJECTS =

DPprofile: CMakeFiles/DPprofile.dir/main.cpp.o
DPprofile: CMakeFiles/DPprofile.dir/build.make
DPprofile: CMakeFiles/DPprofile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/amir/CLionProjects/DPprofile/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DPprofile"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DPprofile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DPprofile.dir/build: DPprofile

.PHONY : CMakeFiles/DPprofile.dir/build

CMakeFiles/DPprofile.dir/requires: CMakeFiles/DPprofile.dir/main.cpp.o.requires

.PHONY : CMakeFiles/DPprofile.dir/requires

CMakeFiles/DPprofile.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DPprofile.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DPprofile.dir/clean

CMakeFiles/DPprofile.dir/depend:
	cd /Users/amir/CLionProjects/DPprofile/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amir/CLionProjects/DPprofile /Users/amir/CLionProjects/DPprofile /Users/amir/CLionProjects/DPprofile/cmake-build-debug /Users/amir/CLionProjects/DPprofile/cmake-build-debug /Users/amir/CLionProjects/DPprofile/cmake-build-debug/CMakeFiles/DPprofile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DPprofile.dir/depend

