# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial\build

# Include any dependencies generated for this target.
include CMakeFiles/vector-inicial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vector-inicial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vector-inicial.dir/flags.make

CMakeFiles/vector-inicial.dir/main.cpp.obj: CMakeFiles/vector-inicial.dir/flags.make
CMakeFiles/vector-inicial.dir/main.cpp.obj: CMakeFiles/vector-inicial.dir/includes_CXX.rsp
CMakeFiles/vector-inicial.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vector-inicial.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\vector-inicial.dir\main.cpp.obj -c D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial\main.cpp

CMakeFiles/vector-inicial.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector-inicial.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial\main.cpp > CMakeFiles\vector-inicial.dir\main.cpp.i

CMakeFiles/vector-inicial.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector-inicial.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial\main.cpp -o CMakeFiles\vector-inicial.dir\main.cpp.s

# Object files for target vector-inicial
vector__inicial_OBJECTS = \
"CMakeFiles/vector-inicial.dir/main.cpp.obj"

# External object files for target vector-inicial
vector__inicial_EXTERNAL_OBJECTS =

debug/vector-inicial.exe: CMakeFiles/vector-inicial.dir/main.cpp.obj
debug/vector-inicial.exe: CMakeFiles/vector-inicial.dir/build.make
debug/vector-inicial.exe: C:/msys64/mingw64/lib/libfmt.a
debug/vector-inicial.exe: CMakeFiles/vector-inicial.dir/linklibs.rsp
debug/vector-inicial.exe: CMakeFiles/vector-inicial.dir/objects1.rsp
debug/vector-inicial.exe: CMakeFiles/vector-inicial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable debug\vector-inicial.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\vector-inicial.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vector-inicial.dir/build: debug/vector-inicial.exe

.PHONY : CMakeFiles/vector-inicial.dir/build

CMakeFiles/vector-inicial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\vector-inicial.dir\cmake_clean.cmake
.PHONY : CMakeFiles/vector-inicial.dir/clean

CMakeFiles/vector-inicial.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial\build D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial\build D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\vector-inicial\build\CMakeFiles\vector-inicial.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vector-inicial.dir/depend

