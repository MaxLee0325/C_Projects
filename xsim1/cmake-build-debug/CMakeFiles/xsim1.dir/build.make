# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /users/cs/yongteng/tmp/tmp.8vS6FSk1oK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/xsim1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xsim1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xsim1.dir/flags.make

CMakeFiles/xsim1.dir/main.c.o: CMakeFiles/xsim1.dir/flags.make
CMakeFiles/xsim1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/cs/yongteng/tmp/tmp.8vS6FSk1oK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/xsim1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xsim1.dir/main.c.o -c /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/main.c

CMakeFiles/xsim1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xsim1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/main.c > CMakeFiles/xsim1.dir/main.c.i

CMakeFiles/xsim1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xsim1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/main.c -o CMakeFiles/xsim1.dir/main.c.s

CMakeFiles/xsim1.dir/xcpuprnt.c.o: CMakeFiles/xsim1.dir/flags.make
CMakeFiles/xsim1.dir/xcpuprnt.c.o: ../xcpuprnt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/cs/yongteng/tmp/tmp.8vS6FSk1oK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/xsim1.dir/xcpuprnt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xsim1.dir/xcpuprnt.c.o -c /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/xcpuprnt.c

CMakeFiles/xsim1.dir/xcpuprnt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xsim1.dir/xcpuprnt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/xcpuprnt.c > CMakeFiles/xsim1.dir/xcpuprnt.c.i

CMakeFiles/xsim1.dir/xcpuprnt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xsim1.dir/xcpuprnt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/xcpuprnt.c -o CMakeFiles/xsim1.dir/xcpuprnt.c.s

CMakeFiles/xsim1.dir/xmem.c.o: CMakeFiles/xsim1.dir/flags.make
CMakeFiles/xsim1.dir/xmem.c.o: ../xmem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/cs/yongteng/tmp/tmp.8vS6FSk1oK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/xsim1.dir/xmem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xsim1.dir/xmem.c.o -c /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/xmem.c

CMakeFiles/xsim1.dir/xmem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xsim1.dir/xmem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/xmem.c > CMakeFiles/xsim1.dir/xmem.c.i

CMakeFiles/xsim1.dir/xmem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xsim1.dir/xmem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/xmem.c -o CMakeFiles/xsim1.dir/xmem.c.s

# Object files for target xsim1
xsim1_OBJECTS = \
"CMakeFiles/xsim1.dir/main.c.o" \
"CMakeFiles/xsim1.dir/xcpuprnt.c.o" \
"CMakeFiles/xsim1.dir/xmem.c.o"

# External object files for target xsim1
xsim1_EXTERNAL_OBJECTS = \
"/users/cs/yongteng/tmp/tmp.8vS6FSk1oK/xcpu.o"

xsim1: CMakeFiles/xsim1.dir/main.c.o
xsim1: CMakeFiles/xsim1.dir/xcpuprnt.c.o
xsim1: CMakeFiles/xsim1.dir/xmem.c.o
xsim1: ../xcpu.o
xsim1: CMakeFiles/xsim1.dir/build.make
xsim1: CMakeFiles/xsim1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/cs/yongteng/tmp/tmp.8vS6FSk1oK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable xsim1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xsim1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xsim1.dir/build: xsim1

.PHONY : CMakeFiles/xsim1.dir/build

CMakeFiles/xsim1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xsim1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xsim1.dir/clean

CMakeFiles/xsim1.dir/depend:
	cd /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/cs/yongteng/tmp/tmp.8vS6FSk1oK /users/cs/yongteng/tmp/tmp.8vS6FSk1oK /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/cmake-build-debug /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/cmake-build-debug /users/cs/yongteng/tmp/tmp.8vS6FSk1oK/cmake-build-debug/CMakeFiles/xsim1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xsim1.dir/depend

