# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = C:\Users\wxz18\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.7141.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\wxz18\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.7141.37\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\wxz18\CLionProjects\c_work

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SinglyLinkedList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SinglyLinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SinglyLinkedList.dir/flags.make

CMakeFiles/SinglyLinkedList.dir/SinglyLinkedList.c.obj: CMakeFiles/SinglyLinkedList.dir/flags.make
CMakeFiles/SinglyLinkedList.dir/SinglyLinkedList.c.obj: ../SinglyLinkedList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SinglyLinkedList.dir/SinglyLinkedList.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SinglyLinkedList.dir\SinglyLinkedList.c.obj   -c C:\Users\wxz18\CLionProjects\c_work\SinglyLinkedList.c

CMakeFiles/SinglyLinkedList.dir/SinglyLinkedList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SinglyLinkedList.dir/SinglyLinkedList.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\wxz18\CLionProjects\c_work\SinglyLinkedList.c > CMakeFiles\SinglyLinkedList.dir\SinglyLinkedList.c.i

CMakeFiles/SinglyLinkedList.dir/SinglyLinkedList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SinglyLinkedList.dir/SinglyLinkedList.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\wxz18\CLionProjects\c_work\SinglyLinkedList.c -o CMakeFiles\SinglyLinkedList.dir\SinglyLinkedList.c.s

# Object files for target SinglyLinkedList
SinglyLinkedList_OBJECTS = \
"CMakeFiles/SinglyLinkedList.dir/SinglyLinkedList.c.obj"

# External object files for target SinglyLinkedList
SinglyLinkedList_EXTERNAL_OBJECTS =

SinglyLinkedList.exe: CMakeFiles/SinglyLinkedList.dir/SinglyLinkedList.c.obj
SinglyLinkedList.exe: CMakeFiles/SinglyLinkedList.dir/build.make
SinglyLinkedList.exe: CMakeFiles/SinglyLinkedList.dir/linklibs.rsp
SinglyLinkedList.exe: CMakeFiles/SinglyLinkedList.dir/objects1.rsp
SinglyLinkedList.exe: CMakeFiles/SinglyLinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SinglyLinkedList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SinglyLinkedList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SinglyLinkedList.dir/build: SinglyLinkedList.exe

.PHONY : CMakeFiles/SinglyLinkedList.dir/build

CMakeFiles/SinglyLinkedList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SinglyLinkedList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SinglyLinkedList.dir/clean

CMakeFiles/SinglyLinkedList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\wxz18\CLionProjects\c_work C:\Users\wxz18\CLionProjects\c_work C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug\CMakeFiles\singlyLinkedList.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SinglyLinkedList.dir/depend
