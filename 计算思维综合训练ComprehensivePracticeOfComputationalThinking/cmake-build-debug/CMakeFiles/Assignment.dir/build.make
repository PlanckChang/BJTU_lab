# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Assignment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment.dir/flags.make

CMakeFiles/Assignment.dir/main.cpp.obj: CMakeFiles/Assignment.dir/flags.make
CMakeFiles/Assignment.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment.dir/main.cpp.obj"
	D:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment.dir\main.cpp.obj -c "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment\main.cpp"

CMakeFiles/Assignment.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment.dir/main.cpp.i"
	D:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment\main.cpp" > CMakeFiles\Assignment.dir\main.cpp.i

CMakeFiles/Assignment.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment.dir/main.cpp.s"
	D:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment\main.cpp" -o CMakeFiles\Assignment.dir\main.cpp.s

# Object files for target Assignment
Assignment_OBJECTS = \
"CMakeFiles/Assignment.dir/main.cpp.obj"

# External object files for target Assignment
Assignment_EXTERNAL_OBJECTS =

Assignment.exe: CMakeFiles/Assignment.dir/main.cpp.obj
Assignment.exe: CMakeFiles/Assignment.dir/build.make
Assignment.exe: CMakeFiles/Assignment.dir/linklibs.rsp
Assignment.exe: CMakeFiles/Assignment.dir/objects1.rsp
Assignment.exe: CMakeFiles/Assignment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Assignment.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment.dir/build: Assignment.exe
.PHONY : CMakeFiles/Assignment.dir/build

CMakeFiles/Assignment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment.dir/clean

CMakeFiles/Assignment.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment" "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment" "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment\cmake-build-debug" "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment\cmake-build-debug" "D:\BJTU\subject\Second semester of sophomore\CS Mindset Comprehensive Training\Assignment\cmake-build-debug\CMakeFiles\Assignment.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment.dir/depend

