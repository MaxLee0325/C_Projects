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
CMAKE_SOURCE_DIR = /users/cs/yongteng/tmp/tmp.jJwkoFwBPT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/cs/yongteng/tmp/tmp.jJwkoFwBPT/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/spellbee.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spellbee.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spellbee.dir/flags.make

CMakeFiles/spellbee.dir/main.c.o: CMakeFiles/spellbee.dir/flags.make
CMakeFiles/spellbee.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/cs/yongteng/tmp/tmp.jJwkoFwBPT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/spellbee.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spellbee.dir/main.c.o -c /users/cs/yongteng/tmp/tmp.jJwkoFwBPT/main.c

CMakeFiles/spellbee.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spellbee.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/cs/yongteng/tmp/tmp.jJwkoFwBPT/main.c > CMakeFiles/spellbee.dir/main.c.i

CMakeFiles/spellbee.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spellbee.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/cs/yongteng/tmp/tmp.jJwkoFwBPT/main.c -o CMakeFiles/spellbee.dir/main.c.s

# Object files for target spellbee
spellbee_OBJECTS = \
"CMakeFiles/spellbee.dir/main.c.o"

# External object files for target spellbee
spellbee_EXTERNAL_OBJECTS =

spellbee: CMakeFiles/spellbee.dir/main.c.o
spellbee: CMakeFiles/spellbee.dir/build.make
spellbee: CMakeFiles/spellbee.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/cs/yongteng/tmp/tmp.jJwkoFwBPT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable spellbee"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spellbee.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spellbee.dir/build: spellbee

.PHONY : CMakeFiles/spellbee.dir/build

CMakeFiles/spellbee.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spellbee.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spellbee.dir/clean

CMakeFiles/spellbee.dir/depend:
	cd /users/cs/yongteng/tmp/tmp.jJwkoFwBPT/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/cs/yongteng/tmp/tmp.jJwkoFwBPT /users/cs/yongteng/tmp/tmp.jJwkoFwBPT /users/cs/yongteng/tmp/tmp.jJwkoFwBPT/cmake-build-debug /users/cs/yongteng/tmp/tmp.jJwkoFwBPT/cmake-build-debug /users/cs/yongteng/tmp/tmp.jJwkoFwBPT/cmake-build-debug/CMakeFiles/spellbee.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spellbee.dir/depend

