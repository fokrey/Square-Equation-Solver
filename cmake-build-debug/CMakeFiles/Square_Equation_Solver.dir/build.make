# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Square_Equation_Solver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Square_Equation_Solver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Square_Equation_Solver.dir/flags.make

CMakeFiles/Square_Equation_Solver.dir/main.cpp.obj: CMakeFiles/Square_Equation_Solver.dir/flags.make
CMakeFiles/Square_Equation_Solver.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Square_Equation_Solver.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Square_Equation_Solver.dir\main.cpp.obj -c C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\main.cpp

CMakeFiles/Square_Equation_Solver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Square_Equation_Solver.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\main.cpp > CMakeFiles\Square_Equation_Solver.dir\main.cpp.i

CMakeFiles/Square_Equation_Solver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Square_Equation_Solver.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\main.cpp -o CMakeFiles\Square_Equation_Solver.dir\main.cpp.s

CMakeFiles/Square_Equation_Solver.dir/SolveSquare.cpp.obj: CMakeFiles/Square_Equation_Solver.dir/flags.make
CMakeFiles/Square_Equation_Solver.dir/SolveSquare.cpp.obj: ../SolveSquare.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Square_Equation_Solver.dir/SolveSquare.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Square_Equation_Solver.dir\SolveSquare.cpp.obj -c C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\SolveSquare.cpp

CMakeFiles/Square_Equation_Solver.dir/SolveSquare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Square_Equation_Solver.dir/SolveSquare.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\SolveSquare.cpp > CMakeFiles\Square_Equation_Solver.dir\SolveSquare.cpp.i

CMakeFiles/Square_Equation_Solver.dir/SolveSquare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Square_Equation_Solver.dir/SolveSquare.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\SolveSquare.cpp -o CMakeFiles\Square_Equation_Solver.dir\SolveSquare.cpp.s

# Object files for target Square_Equation_Solver
Square_Equation_Solver_OBJECTS = \
"CMakeFiles/Square_Equation_Solver.dir/main.cpp.obj" \
"CMakeFiles/Square_Equation_Solver.dir/SolveSquare.cpp.obj"

# External object files for target Square_Equation_Solver
Square_Equation_Solver_EXTERNAL_OBJECTS =

Square_Equation_Solver.exe: CMakeFiles/Square_Equation_Solver.dir/main.cpp.obj
Square_Equation_Solver.exe: CMakeFiles/Square_Equation_Solver.dir/SolveSquare.cpp.obj
Square_Equation_Solver.exe: CMakeFiles/Square_Equation_Solver.dir/build.make
Square_Equation_Solver.exe: CMakeFiles/Square_Equation_Solver.dir/linklibs.rsp
Square_Equation_Solver.exe: CMakeFiles/Square_Equation_Solver.dir/objects1.rsp
Square_Equation_Solver.exe: CMakeFiles/Square_Equation_Solver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Square_Equation_Solver.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Square_Equation_Solver.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Square_Equation_Solver.dir/build: Square_Equation_Solver.exe

.PHONY : CMakeFiles/Square_Equation_Solver.dir/build

CMakeFiles/Square_Equation_Solver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Square_Equation_Solver.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Square_Equation_Solver.dir/clean

CMakeFiles/Square_Equation_Solver.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\cmake-build-debug C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\cmake-build-debug C:\Users\user\Documents\GitHub\Square-Equation-Solver\Square-Equation-Solver\cmake-build-debug\CMakeFiles\Square_Equation_Solver.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Square_Equation_Solver.dir/depend
