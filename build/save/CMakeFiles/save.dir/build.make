# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/binoll/Desktop/Storage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/binoll/Desktop/Storage/build

# Include any dependencies generated for this target.
include save/CMakeFiles/save.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include save/CMakeFiles/save.dir/compiler_depend.make

# Include the progress variables for this target.
include save/CMakeFiles/save.dir/progress.make

# Include the compile flags for this target's objects.
include save/CMakeFiles/save.dir/flags.make

save/CMakeFiles/save.dir/main.c.o: save/CMakeFiles/save.dir/flags.make
save/CMakeFiles/save.dir/main.c.o: /home/binoll/Desktop/Storage/save/main.c
save/CMakeFiles/save.dir/main.c.o: save/CMakeFiles/save.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/binoll/Desktop/Storage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object save/CMakeFiles/save.dir/main.c.o"
	cd /home/binoll/Desktop/Storage/build/save && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT save/CMakeFiles/save.dir/main.c.o -MF CMakeFiles/save.dir/main.c.o.d -o CMakeFiles/save.dir/main.c.o -c /home/binoll/Desktop/Storage/save/main.c

save/CMakeFiles/save.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/save.dir/main.c.i"
	cd /home/binoll/Desktop/Storage/build/save && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/binoll/Desktop/Storage/save/main.c > CMakeFiles/save.dir/main.c.i

save/CMakeFiles/save.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/save.dir/main.c.s"
	cd /home/binoll/Desktop/Storage/build/save && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/binoll/Desktop/Storage/save/main.c -o CMakeFiles/save.dir/main.c.s

save/CMakeFiles/save.dir/save_file.c.o: save/CMakeFiles/save.dir/flags.make
save/CMakeFiles/save.dir/save_file.c.o: /home/binoll/Desktop/Storage/save/save_file.c
save/CMakeFiles/save.dir/save_file.c.o: save/CMakeFiles/save.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/binoll/Desktop/Storage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object save/CMakeFiles/save.dir/save_file.c.o"
	cd /home/binoll/Desktop/Storage/build/save && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT save/CMakeFiles/save.dir/save_file.c.o -MF CMakeFiles/save.dir/save_file.c.o.d -o CMakeFiles/save.dir/save_file.c.o -c /home/binoll/Desktop/Storage/save/save_file.c

save/CMakeFiles/save.dir/save_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/save.dir/save_file.c.i"
	cd /home/binoll/Desktop/Storage/build/save && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/binoll/Desktop/Storage/save/save_file.c > CMakeFiles/save.dir/save_file.c.i

save/CMakeFiles/save.dir/save_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/save.dir/save_file.c.s"
	cd /home/binoll/Desktop/Storage/build/save && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/binoll/Desktop/Storage/save/save_file.c -o CMakeFiles/save.dir/save_file.c.s

# Object files for target save
save_OBJECTS = \
"CMakeFiles/save.dir/main.c.o" \
"CMakeFiles/save.dir/save_file.c.o"

# External object files for target save
save_EXTERNAL_OBJECTS =

save/save: save/CMakeFiles/save.dir/main.c.o
save/save: save/CMakeFiles/save.dir/save_file.c.o
save/save: save/CMakeFiles/save.dir/build.make
save/save: save/CMakeFiles/save.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/binoll/Desktop/Storage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable save"
	cd /home/binoll/Desktop/Storage/build/save && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/save.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
save/CMakeFiles/save.dir/build: save/save
.PHONY : save/CMakeFiles/save.dir/build

save/CMakeFiles/save.dir/clean:
	cd /home/binoll/Desktop/Storage/build/save && $(CMAKE_COMMAND) -P CMakeFiles/save.dir/cmake_clean.cmake
.PHONY : save/CMakeFiles/save.dir/clean

save/CMakeFiles/save.dir/depend:
	cd /home/binoll/Desktop/Storage/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/binoll/Desktop/Storage /home/binoll/Desktop/Storage/save /home/binoll/Desktop/Storage/build /home/binoll/Desktop/Storage/build/save /home/binoll/Desktop/Storage/build/save/CMakeFiles/save.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : save/CMakeFiles/save.dir/depend

