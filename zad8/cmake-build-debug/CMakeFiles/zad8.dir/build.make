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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Filip\CLionProjects\zad8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Filip\CLionProjects\zad8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zad8.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/zad8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zad8.dir/flags.make

CMakeFiles/zad8.dir/main.cpp.obj: CMakeFiles/zad8.dir/flags.make
CMakeFiles/zad8.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zad8.dir/main.cpp.obj"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zad8.dir\main.cpp.obj -c C:\Users\Filip\CLionProjects\zad8\main.cpp

CMakeFiles/zad8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad8.dir/main.cpp.i"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Filip\CLionProjects\zad8\main.cpp > CMakeFiles\zad8.dir\main.cpp.i

CMakeFiles/zad8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad8.dir/main.cpp.s"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Filip\CLionProjects\zad8\main.cpp -o CMakeFiles\zad8.dir\main.cpp.s

CMakeFiles/zad8.dir/algorithms/random.cpp.obj: CMakeFiles/zad8.dir/flags.make
CMakeFiles/zad8.dir/algorithms/random.cpp.obj: ../algorithms/random.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zad8.dir/algorithms/random.cpp.obj"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zad8.dir\algorithms\random.cpp.obj -c C:\Users\Filip\CLionProjects\zad8\algorithms\random.cpp

CMakeFiles/zad8.dir/algorithms/random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad8.dir/algorithms/random.cpp.i"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Filip\CLionProjects\zad8\algorithms\random.cpp > CMakeFiles\zad8.dir\algorithms\random.cpp.i

CMakeFiles/zad8.dir/algorithms/random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad8.dir/algorithms/random.cpp.s"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Filip\CLionProjects\zad8\algorithms\random.cpp -o CMakeFiles\zad8.dir\algorithms\random.cpp.s

CMakeFiles/zad8.dir/base_functions.cpp.obj: CMakeFiles/zad8.dir/flags.make
CMakeFiles/zad8.dir/base_functions.cpp.obj: ../base_functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/zad8.dir/base_functions.cpp.obj"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zad8.dir\base_functions.cpp.obj -c C:\Users\Filip\CLionProjects\zad8\base_functions.cpp

CMakeFiles/zad8.dir/base_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad8.dir/base_functions.cpp.i"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Filip\CLionProjects\zad8\base_functions.cpp > CMakeFiles\zad8.dir\base_functions.cpp.i

CMakeFiles/zad8.dir/base_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad8.dir/base_functions.cpp.s"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Filip\CLionProjects\zad8\base_functions.cpp -o CMakeFiles\zad8.dir\base_functions.cpp.s

CMakeFiles/zad8.dir/base_for_puzzles.cpp.obj: CMakeFiles/zad8.dir/flags.make
CMakeFiles/zad8.dir/base_for_puzzles.cpp.obj: ../base_for_puzzles.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/zad8.dir/base_for_puzzles.cpp.obj"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zad8.dir\base_for_puzzles.cpp.obj -c C:\Users\Filip\CLionProjects\zad8\base_for_puzzles.cpp

CMakeFiles/zad8.dir/base_for_puzzles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad8.dir/base_for_puzzles.cpp.i"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Filip\CLionProjects\zad8\base_for_puzzles.cpp > CMakeFiles\zad8.dir\base_for_puzzles.cpp.i

CMakeFiles/zad8.dir/base_for_puzzles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad8.dir/base_for_puzzles.cpp.s"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Filip\CLionProjects\zad8\base_for_puzzles.cpp -o CMakeFiles\zad8.dir\base_for_puzzles.cpp.s

CMakeFiles/zad8.dir/algorithms/brute.cpp.obj: CMakeFiles/zad8.dir/flags.make
CMakeFiles/zad8.dir/algorithms/brute.cpp.obj: ../algorithms/brute.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/zad8.dir/algorithms/brute.cpp.obj"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zad8.dir\algorithms\brute.cpp.obj -c C:\Users\Filip\CLionProjects\zad8\algorithms\brute.cpp

CMakeFiles/zad8.dir/algorithms/brute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad8.dir/algorithms/brute.cpp.i"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Filip\CLionProjects\zad8\algorithms\brute.cpp > CMakeFiles\zad8.dir\algorithms\brute.cpp.i

CMakeFiles/zad8.dir/algorithms/brute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad8.dir/algorithms/brute.cpp.s"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Filip\CLionProjects\zad8\algorithms\brute.cpp -o CMakeFiles\zad8.dir\algorithms\brute.cpp.s

CMakeFiles/zad8.dir/algorithms/hills.cpp.obj: CMakeFiles/zad8.dir/flags.make
CMakeFiles/zad8.dir/algorithms/hills.cpp.obj: ../algorithms/hills.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/zad8.dir/algorithms/hills.cpp.obj"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zad8.dir\algorithms\hills.cpp.obj -c C:\Users\Filip\CLionProjects\zad8\algorithms\hills.cpp

CMakeFiles/zad8.dir/algorithms/hills.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad8.dir/algorithms/hills.cpp.i"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Filip\CLionProjects\zad8\algorithms\hills.cpp > CMakeFiles\zad8.dir\algorithms\hills.cpp.i

CMakeFiles/zad8.dir/algorithms/hills.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad8.dir/algorithms/hills.cpp.s"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Filip\CLionProjects\zad8\algorithms\hills.cpp -o CMakeFiles\zad8.dir\algorithms\hills.cpp.s

CMakeFiles/zad8.dir/algorithms/tabu.cpp.obj: CMakeFiles/zad8.dir/flags.make
CMakeFiles/zad8.dir/algorithms/tabu.cpp.obj: ../algorithms/tabu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/zad8.dir/algorithms/tabu.cpp.obj"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zad8.dir\algorithms\tabu.cpp.obj -c C:\Users\Filip\CLionProjects\zad8\algorithms\tabu.cpp

CMakeFiles/zad8.dir/algorithms/tabu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad8.dir/algorithms/tabu.cpp.i"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Filip\CLionProjects\zad8\algorithms\tabu.cpp > CMakeFiles\zad8.dir\algorithms\tabu.cpp.i

CMakeFiles/zad8.dir/algorithms/tabu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad8.dir/algorithms/tabu.cpp.s"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Filip\CLionProjects\zad8\algorithms\tabu.cpp -o CMakeFiles\zad8.dir\algorithms\tabu.cpp.s

CMakeFiles/zad8.dir/algorithms/annealing.cpp.obj: CMakeFiles/zad8.dir/flags.make
CMakeFiles/zad8.dir/algorithms/annealing.cpp.obj: ../algorithms/annealing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/zad8.dir/algorithms/annealing.cpp.obj"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zad8.dir\algorithms\annealing.cpp.obj -c C:\Users\Filip\CLionProjects\zad8\algorithms\annealing.cpp

CMakeFiles/zad8.dir/algorithms/annealing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad8.dir/algorithms/annealing.cpp.i"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Filip\CLionProjects\zad8\algorithms\annealing.cpp > CMakeFiles\zad8.dir\algorithms\annealing.cpp.i

CMakeFiles/zad8.dir/algorithms/annealing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad8.dir/algorithms/annealing.cpp.s"
	"D:\Program Files\minGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Filip\CLionProjects\zad8\algorithms\annealing.cpp -o CMakeFiles\zad8.dir\algorithms\annealing.cpp.s

# Object files for target zad8
zad8_OBJECTS = \
"CMakeFiles/zad8.dir/main.cpp.obj" \
"CMakeFiles/zad8.dir/algorithms/random.cpp.obj" \
"CMakeFiles/zad8.dir/base_functions.cpp.obj" \
"CMakeFiles/zad8.dir/base_for_puzzles.cpp.obj" \
"CMakeFiles/zad8.dir/algorithms/brute.cpp.obj" \
"CMakeFiles/zad8.dir/algorithms/hills.cpp.obj" \
"CMakeFiles/zad8.dir/algorithms/tabu.cpp.obj" \
"CMakeFiles/zad8.dir/algorithms/annealing.cpp.obj"

# External object files for target zad8
zad8_EXTERNAL_OBJECTS =

zad8.exe: CMakeFiles/zad8.dir/main.cpp.obj
zad8.exe: CMakeFiles/zad8.dir/algorithms/random.cpp.obj
zad8.exe: CMakeFiles/zad8.dir/base_functions.cpp.obj
zad8.exe: CMakeFiles/zad8.dir/base_for_puzzles.cpp.obj
zad8.exe: CMakeFiles/zad8.dir/algorithms/brute.cpp.obj
zad8.exe: CMakeFiles/zad8.dir/algorithms/hills.cpp.obj
zad8.exe: CMakeFiles/zad8.dir/algorithms/tabu.cpp.obj
zad8.exe: CMakeFiles/zad8.dir/algorithms/annealing.cpp.obj
zad8.exe: CMakeFiles/zad8.dir/build.make
zad8.exe: CMakeFiles/zad8.dir/linklibs.rsp
zad8.exe: CMakeFiles/zad8.dir/objects1.rsp
zad8.exe: CMakeFiles/zad8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable zad8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zad8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zad8.dir/build: zad8.exe
.PHONY : CMakeFiles/zad8.dir/build

CMakeFiles/zad8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zad8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zad8.dir/clean

CMakeFiles/zad8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Filip\CLionProjects\zad8 C:\Users\Filip\CLionProjects\zad8 C:\Users\Filip\CLionProjects\zad8\cmake-build-debug C:\Users\Filip\CLionProjects\zad8\cmake-build-debug C:\Users\Filip\CLionProjects\zad8\cmake-build-debug\CMakeFiles\zad8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zad8.dir/depend

