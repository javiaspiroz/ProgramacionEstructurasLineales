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
CMAKE_SOURCE_DIR = D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad\build

# Include any dependencies generated for this target.
include CMakeFiles/recursividad.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/recursividad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/recursividad.dir/flags.make

CMakeFiles/recursividad.dir/main.cpp.obj: CMakeFiles/recursividad.dir/flags.make
CMakeFiles/recursividad.dir/main.cpp.obj: CMakeFiles/recursividad.dir/includes_CXX.rsp
CMakeFiles/recursividad.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/recursividad.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\recursividad.dir\main.cpp.obj -c D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad\main.cpp

CMakeFiles/recursividad.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recursividad.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad\main.cpp > CMakeFiles\recursividad.dir\main.cpp.i

CMakeFiles/recursividad.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recursividad.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad\main.cpp -o CMakeFiles\recursividad.dir\main.cpp.s

# Object files for target recursividad
recursividad_OBJECTS = \
"CMakeFiles/recursividad.dir/main.cpp.obj"

# External object files for target recursividad
recursividad_EXTERNAL_OBJECTS =

debug/recursividad.exe: CMakeFiles/recursividad.dir/main.cpp.obj
debug/recursividad.exe: CMakeFiles/recursividad.dir/build.make
debug/recursividad.exe: C:/msys64/mingw64/lib/libfmt.a
debug/recursividad.exe: CMakeFiles/recursividad.dir/linklibs.rsp
debug/recursividad.exe: CMakeFiles/recursividad.dir/objects1.rsp
debug/recursividad.exe: CMakeFiles/recursividad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable debug\recursividad.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\recursividad.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/recursividad.dir/build: debug/recursividad.exe

.PHONY : CMakeFiles/recursividad.dir/build

CMakeFiles/recursividad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\recursividad.dir\cmake_clean.cmake
.PHONY : CMakeFiles/recursividad.dir/clean

CMakeFiles/recursividad.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad\build D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad\build D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\recursividad\build\CMakeFiles\recursividad.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/recursividad.dir/depend

