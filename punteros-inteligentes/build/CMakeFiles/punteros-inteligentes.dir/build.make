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
CMAKE_SOURCE_DIR = D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes\build

# Include any dependencies generated for this target.
include CMakeFiles/punteros-inteligentes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/punteros-inteligentes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/punteros-inteligentes.dir/flags.make

CMakeFiles/punteros-inteligentes.dir/main.cpp.obj: CMakeFiles/punteros-inteligentes.dir/flags.make
CMakeFiles/punteros-inteligentes.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/punteros-inteligentes.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\punteros-inteligentes.dir\main.cpp.obj -c D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes\main.cpp

CMakeFiles/punteros-inteligentes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/punteros-inteligentes.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes\main.cpp > CMakeFiles\punteros-inteligentes.dir\main.cpp.i

CMakeFiles/punteros-inteligentes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/punteros-inteligentes.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes\main.cpp -o CMakeFiles\punteros-inteligentes.dir\main.cpp.s

# Object files for target punteros-inteligentes
punteros__inteligentes_OBJECTS = \
"CMakeFiles/punteros-inteligentes.dir/main.cpp.obj"

# External object files for target punteros-inteligentes
punteros__inteligentes_EXTERNAL_OBJECTS =

punteros-inteligentes.exe: CMakeFiles/punteros-inteligentes.dir/main.cpp.obj
punteros-inteligentes.exe: CMakeFiles/punteros-inteligentes.dir/build.make
punteros-inteligentes.exe: CMakeFiles/punteros-inteligentes.dir/linklibs.rsp
punteros-inteligentes.exe: CMakeFiles/punteros-inteligentes.dir/objects1.rsp
punteros-inteligentes.exe: CMakeFiles/punteros-inteligentes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable punteros-inteligentes.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\punteros-inteligentes.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/punteros-inteligentes.dir/build: punteros-inteligentes.exe

.PHONY : CMakeFiles/punteros-inteligentes.dir/build

CMakeFiles/punteros-inteligentes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\punteros-inteligentes.dir\cmake_clean.cmake
.PHONY : CMakeFiles/punteros-inteligentes.dir/clean

CMakeFiles/punteros-inteligentes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes\build D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes\build D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\punteros-inteligentes\build\CMakeFiles\punteros-inteligentes.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/punteros-inteligentes.dir/depend

