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
CMAKE_SOURCE_DIR = D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo\build

# Include any dependencies generated for this target.
include CMakeFiles/palindromo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/palindromo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/palindromo.dir/flags.make

CMakeFiles/palindromo.dir/main.cpp.obj: CMakeFiles/palindromo.dir/flags.make
CMakeFiles/palindromo.dir/main.cpp.obj: CMakeFiles/palindromo.dir/includes_CXX.rsp
CMakeFiles/palindromo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/palindromo.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\palindromo.dir\main.cpp.obj -c D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo\main.cpp

CMakeFiles/palindromo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/palindromo.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo\main.cpp > CMakeFiles\palindromo.dir\main.cpp.i

CMakeFiles/palindromo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/palindromo.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo\main.cpp -o CMakeFiles\palindromo.dir\main.cpp.s

# Object files for target palindromo
palindromo_OBJECTS = \
"CMakeFiles/palindromo.dir/main.cpp.obj"

# External object files for target palindromo
palindromo_EXTERNAL_OBJECTS =

debug/palindromo.exe: CMakeFiles/palindromo.dir/main.cpp.obj
debug/palindromo.exe: CMakeFiles/palindromo.dir/build.make
debug/palindromo.exe: C:/msys64/mingw64/lib/libfmt.a
debug/palindromo.exe: CMakeFiles/palindromo.dir/linklibs.rsp
debug/palindromo.exe: CMakeFiles/palindromo.dir/objects1.rsp
debug/palindromo.exe: CMakeFiles/palindromo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable debug\palindromo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\palindromo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/palindromo.dir/build: debug/palindromo.exe

.PHONY : CMakeFiles/palindromo.dir/build

CMakeFiles/palindromo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\palindromo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/palindromo.dir/clean

CMakeFiles/palindromo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo\build D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo\build D:\MisDocumentos\UEM\Proyectos\ProgramacionEstructurasLineales\palindromo\build\CMakeFiles\palindromo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/palindromo.dir/depend
