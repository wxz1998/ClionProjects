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
include CMakeFiles/YueSeFuHuan.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/YueSeFuHuan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/YueSeFuHuan.dir/flags.make

CMakeFiles/YueSeFuHuan.dir/YueSeFuHuan.c.obj: CMakeFiles/YueSeFuHuan.dir/flags.make
CMakeFiles/YueSeFuHuan.dir/YueSeFuHuan.c.obj: ../YueSeFuHuan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/YueSeFuHuan.dir/YueSeFuHuan.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\YueSeFuHuan.dir\YueSeFuHuan.c.obj   -c C:\Users\wxz18\CLionProjects\c_work\YueSeFuHuan.c

CMakeFiles/YueSeFuHuan.dir/YueSeFuHuan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/YueSeFuHuan.dir/YueSeFuHuan.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\wxz18\CLionProjects\c_work\YueSeFuHuan.c > CMakeFiles\YueSeFuHuan.dir\YueSeFuHuan.c.i

CMakeFiles/YueSeFuHuan.dir/YueSeFuHuan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/YueSeFuHuan.dir/YueSeFuHuan.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\wxz18\CLionProjects\c_work\YueSeFuHuan.c -o CMakeFiles\YueSeFuHuan.dir\YueSeFuHuan.c.s

# Object files for target YueSeFuHuan
YueSeFuHuan_OBJECTS = \
"CMakeFiles/YueSeFuHuan.dir/YueSeFuHuan.c.obj"

# External object files for target YueSeFuHuan
YueSeFuHuan_EXTERNAL_OBJECTS =

YueSeFuHuan.exe: CMakeFiles/YueSeFuHuan.dir/YueSeFuHuan.c.obj
YueSeFuHuan.exe: CMakeFiles/YueSeFuHuan.dir/build.make
YueSeFuHuan.exe: CMakeFiles/YueSeFuHuan.dir/linklibs.rsp
YueSeFuHuan.exe: CMakeFiles/YueSeFuHuan.dir/objects1.rsp
YueSeFuHuan.exe: CMakeFiles/YueSeFuHuan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable YueSeFuHuan.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\YueSeFuHuan.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/YueSeFuHuan.dir/build: YueSeFuHuan.exe

.PHONY : CMakeFiles/YueSeFuHuan.dir/build

CMakeFiles/YueSeFuHuan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\YueSeFuHuan.dir\cmake_clean.cmake
.PHONY : CMakeFiles/YueSeFuHuan.dir/clean

CMakeFiles/YueSeFuHuan.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\wxz18\CLionProjects\c_work C:\Users\wxz18\CLionProjects\c_work C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug C:\Users\wxz18\CLionProjects\c_work\cmake-build-debug\CMakeFiles\YueSeFuHuan.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/YueSeFuHuan.dir/depend
