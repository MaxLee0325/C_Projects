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
CMAKE_SOURCE_DIR = /users/cs/yongteng/tmp/tmp.bhbAh1U8io

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/xsim2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xsim2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xsim2.dir/flags.make

CMakeFiles/xsim2.dir/main.c.o: CMakeFiles/xsim2.dir/flags.make
CMakeFiles/xsim2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/xsim2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xsim2.dir/main.c.o -c /users/cs/yongteng/tmp/tmp.bhbAh1U8io/main.c

CMakeFiles/xsim2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xsim2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/cs/yongteng/tmp/tmp.bhbAh1U8io/main.c > CMakeFiles/xsim2.dir/main.c.i

CMakeFiles/xsim2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xsim2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/cs/yongteng/tmp/tmp.bhbAh1U8io/main.c -o CMakeFiles/xsim2.dir/main.c.s

CMakeFiles/xsim2.dir/xcpu.c.o: CMakeFiles/xsim2.dir/flags.make
CMakeFiles/xsim2.dir/xcpu.c.o: ../xcpu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/xsim2.dir/xcpu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xsim2.dir/xcpu.c.o -c /users/cs/yongteng/tmp/tmp.bhbAh1U8io/xcpu.c

CMakeFiles/xsim2.dir/xcpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xsim2.dir/xcpu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/cs/yongteng/tmp/tmp.bhbAh1U8io/xcpu.c > CMakeFiles/xsim2.dir/xcpu.c.i

CMakeFiles/xsim2.dir/xcpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xsim2.dir/xcpu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/cs/yongteng/tmp/tmp.bhbAh1U8io/xcpu.c -o CMakeFiles/xsim2.dir/xcpu.c.s

CMakeFiles/xsim2.dir/xcpuprnt.c.o: CMakeFiles/xsim2.dir/flags.make
CMakeFiles/xsim2.dir/xcpuprnt.c.o: ../xcpuprnt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/xsim2.dir/xcpuprnt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xsim2.dir/xcpuprnt.c.o -c /users/cs/yongteng/tmp/tmp.bhbAh1U8io/xcpuprnt.c

CMakeFiles/xsim2.dir/xcpuprnt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xsim2.dir/xcpuprnt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/cs/yongteng/tmp/tmp.bhbAh1U8io/xcpuprnt.c > CMakeFiles/xsim2.dir/xcpuprnt.c.i

CMakeFiles/xsim2.dir/xcpuprnt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xsim2.dir/xcpuprnt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/cs/yongteng/tmp/tmp.bhbAh1U8io/xcpuprnt.c -o CMakeFiles/xsim2.dir/xcpuprnt.c.s

CMakeFiles/xsim2.dir/xmem.c.o: CMakeFiles/xsim2.dir/flags.make
CMakeFiles/xsim2.dir/xmem.c.o: ../xmem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/xsim2.dir/xmem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xsim2.dir/xmem.c.o -c /users/cs/yongteng/tmp/tmp.bhbAh1U8io/xmem.c

CMakeFiles/xsim2.dir/xmem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xsim2.dir/xmem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/cs/yongteng/tmp/tmp.bhbAh1U8io/xmem.c > CMakeFiles/xsim2.dir/xmem.c.i

CMakeFiles/xsim2.dir/xmem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xsim2.dir/xmem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/cs/yongteng/tmp/tmp.bhbAh1U8io/xmem.c -o CMakeFiles/xsim2.dir/xmem.c.s

# Object files for target xsim2
xsim2_OBJECTS = \
"CMakeFiles/xsim2.dir/main.c.o" \
"CMakeFiles/xsim2.dir/xcpu.c.o" \
"CMakeFiles/xsim2.dir/xcpuprnt.c.o" \
"CMakeFiles/xsim2.dir/xmem.c.o"

# External object files for target xsim2
xsim2_EXTERNAL_OBJECTS =

xsim2: CMakeFiles/xsim2.dir/main.c.o
xsim2: CMakeFiles/xsim2.dir/xcpu.c.o
xsim2: CMakeFiles/xsim2.dir/xcpuprnt.c.o
xsim2: CMakeFiles/xsim2.dir/xmem.c.o
xsim2: CMakeFiles/xsim2.dir/build.make
xsim2: CMakeFiles/xsim2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable xsim2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xsim2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xsim2.dir/build: xsim2

.PHONY : CMakeFiles/xsim2.dir/build

CMakeFiles/xsim2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xsim2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xsim2.dir/clean

CMakeFiles/xsim2.dir/depend:
	cd /users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/cs/yongteng/tmp/tmp.bhbAh1U8io /users/cs/yongteng/tmp/tmp.bhbAh1U8io /users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug /users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug /users/cs/yongteng/tmp/tmp.bhbAh1U8io/cmake-build-debug/CMakeFiles/xsim2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xsim2.dir/depend
