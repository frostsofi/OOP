# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\frost\CLionProjects\second_semestr\trits2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\frost\CLionProjects\second_semestr\trits2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lib.dir/flags.make

CMakeFiles/lib.dir/main.cpp.obj: CMakeFiles/lib.dir/flags.make
CMakeFiles/lib.dir/main.cpp.obj: CMakeFiles/lib.dir/includes_CXX.rsp
CMakeFiles/lib.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\frost\CLionProjects\second_semestr\trits2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lib.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lib.dir\main.cpp.obj -c C:\Users\frost\CLionProjects\second_semestr\trits2\main.cpp

CMakeFiles/lib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\frost\CLionProjects\second_semestr\trits2\main.cpp > CMakeFiles\lib.dir\main.cpp.i

CMakeFiles/lib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\frost\CLionProjects\second_semestr\trits2\main.cpp -o CMakeFiles\lib.dir\main.cpp.s

CMakeFiles/lib.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/lib.dir/main.cpp.obj.requires

CMakeFiles/lib.dir/main.cpp.obj.provides: CMakeFiles/lib.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\lib.dir\build.make CMakeFiles/lib.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/lib.dir/main.cpp.obj.provides

CMakeFiles/lib.dir/main.cpp.obj.provides.build: CMakeFiles/lib.dir/main.cpp.obj


CMakeFiles/lib.dir/TritSet.cpp.obj: CMakeFiles/lib.dir/flags.make
CMakeFiles/lib.dir/TritSet.cpp.obj: CMakeFiles/lib.dir/includes_CXX.rsp
CMakeFiles/lib.dir/TritSet.cpp.obj: ../TritSet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\frost\CLionProjects\second_semestr\trits2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lib.dir/TritSet.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lib.dir\TritSet.cpp.obj -c C:\Users\frost\CLionProjects\second_semestr\trits2\TritSet.cpp

CMakeFiles/lib.dir/TritSet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/TritSet.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\frost\CLionProjects\second_semestr\trits2\TritSet.cpp > CMakeFiles\lib.dir\TritSet.cpp.i

CMakeFiles/lib.dir/TritSet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/TritSet.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\frost\CLionProjects\second_semestr\trits2\TritSet.cpp -o CMakeFiles\lib.dir\TritSet.cpp.s

CMakeFiles/lib.dir/TritSet.cpp.obj.requires:

.PHONY : CMakeFiles/lib.dir/TritSet.cpp.obj.requires

CMakeFiles/lib.dir/TritSet.cpp.obj.provides: CMakeFiles/lib.dir/TritSet.cpp.obj.requires
	$(MAKE) -f CMakeFiles\lib.dir\build.make CMakeFiles/lib.dir/TritSet.cpp.obj.provides.build
.PHONY : CMakeFiles/lib.dir/TritSet.cpp.obj.provides

CMakeFiles/lib.dir/TritSet.cpp.obj.provides.build: CMakeFiles/lib.dir/TritSet.cpp.obj


CMakeFiles/lib.dir/Tests/Test.cpp.obj: CMakeFiles/lib.dir/flags.make
CMakeFiles/lib.dir/Tests/Test.cpp.obj: CMakeFiles/lib.dir/includes_CXX.rsp
CMakeFiles/lib.dir/Tests/Test.cpp.obj: ../Tests/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\frost\CLionProjects\second_semestr\trits2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lib.dir/Tests/Test.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lib.dir\Tests\Test.cpp.obj -c C:\Users\frost\CLionProjects\second_semestr\trits2\Tests\Test.cpp

CMakeFiles/lib.dir/Tests/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/Tests/Test.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\frost\CLionProjects\second_semestr\trits2\Tests\Test.cpp > CMakeFiles\lib.dir\Tests\Test.cpp.i

CMakeFiles/lib.dir/Tests/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/Tests/Test.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\frost\CLionProjects\second_semestr\trits2\Tests\Test.cpp -o CMakeFiles\lib.dir\Tests\Test.cpp.s

CMakeFiles/lib.dir/Tests/Test.cpp.obj.requires:

.PHONY : CMakeFiles/lib.dir/Tests/Test.cpp.obj.requires

CMakeFiles/lib.dir/Tests/Test.cpp.obj.provides: CMakeFiles/lib.dir/Tests/Test.cpp.obj.requires
	$(MAKE) -f CMakeFiles\lib.dir\build.make CMakeFiles/lib.dir/Tests/Test.cpp.obj.provides.build
.PHONY : CMakeFiles/lib.dir/Tests/Test.cpp.obj.provides

CMakeFiles/lib.dir/Tests/Test.cpp.obj.provides.build: CMakeFiles/lib.dir/Tests/Test.cpp.obj


# Object files for target lib
lib_OBJECTS = \
"CMakeFiles/lib.dir/main.cpp.obj" \
"CMakeFiles/lib.dir/TritSet.cpp.obj" \
"CMakeFiles/lib.dir/Tests/Test.cpp.obj"

# External object files for target lib
lib_EXTERNAL_OBJECTS =

lib.exe: CMakeFiles/lib.dir/main.cpp.obj
lib.exe: CMakeFiles/lib.dir/TritSet.cpp.obj
lib.exe: CMakeFiles/lib.dir/Tests/Test.cpp.obj
lib.exe: CMakeFiles/lib.dir/build.make
lib.exe: CMakeFiles/lib.dir/linklibs.rsp
lib.exe: CMakeFiles/lib.dir/objects1.rsp
lib.exe: CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\frost\CLionProjects\second_semestr\trits2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lib.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lib.dir/build: lib.exe

.PHONY : CMakeFiles/lib.dir/build

CMakeFiles/lib.dir/requires: CMakeFiles/lib.dir/main.cpp.obj.requires
CMakeFiles/lib.dir/requires: CMakeFiles/lib.dir/TritSet.cpp.obj.requires
CMakeFiles/lib.dir/requires: CMakeFiles/lib.dir/Tests/Test.cpp.obj.requires

.PHONY : CMakeFiles/lib.dir/requires

CMakeFiles/lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lib.dir/clean

CMakeFiles/lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\frost\CLionProjects\second_semestr\trits2 C:\Users\frost\CLionProjects\second_semestr\trits2 C:\Users\frost\CLionProjects\second_semestr\trits2\cmake-build-debug C:\Users\frost\CLionProjects\second_semestr\trits2\cmake-build-debug C:\Users\frost\CLionProjects\second_semestr\trits2\cmake-build-debug\CMakeFiles\lib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lib.dir/depend

