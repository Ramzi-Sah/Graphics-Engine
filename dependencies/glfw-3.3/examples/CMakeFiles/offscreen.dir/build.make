# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw"

# Include any dependencies generated for this target.
include dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/depend.make

# Include the progress variables for this target.
include dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/progress.make

# Include the compile flags for this target's objects.
include dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/flags.make

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/flags.make
dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o: dependencies/glfw-3.3/examples/offscreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o"
	cd "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/offscreen.dir/offscreen.c.o   -c "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples/offscreen.c"

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/offscreen.c.i"
	cd "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples/offscreen.c" > CMakeFiles/offscreen.dir/offscreen.c.i

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/offscreen.c.s"
	cd "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples/offscreen.c" -o CMakeFiles/offscreen.dir/offscreen.c.s

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o.requires:

.PHONY : dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o.requires

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o.provides: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o.requires
	$(MAKE) -f dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/build.make dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o.provides.build
.PHONY : dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o.provides

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o.provides.build: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o


dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/flags.make
dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: dependencies/glfw-3.3/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"
	cd "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o   -c "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/deps/glad_gl.c"

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i"
	cd "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/deps/glad_gl.c" > CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s"
	cd "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/deps/glad_gl.c" -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o.requires:

.PHONY : dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o.requires

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o.provides: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o.requires
	$(MAKE) -f dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/build.make dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o.provides.build
.PHONY : dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o.provides

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o.provides.build: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o


# Object files for target offscreen
offscreen_OBJECTS = \
"CMakeFiles/offscreen.dir/offscreen.c.o" \
"CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"

# External object files for target offscreen
offscreen_EXTERNAL_OBJECTS =

dependencies/glfw-3.3/examples/offscreen: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o
dependencies/glfw-3.3/examples/offscreen: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o
dependencies/glfw-3.3/examples/offscreen: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/build.make
dependencies/glfw-3.3/examples/offscreen: dependencies/glfw-3.3/src/libglfw3.a
dependencies/glfw-3.3/examples/offscreen: /usr/lib/x86_64-linux-gnu/libm.so
dependencies/glfw-3.3/examples/offscreen: /usr/lib/x86_64-linux-gnu/librt.so
dependencies/glfw-3.3/examples/offscreen: /usr/lib/x86_64-linux-gnu/libm.so
dependencies/glfw-3.3/examples/offscreen: /usr/lib/x86_64-linux-gnu/libX11.so
dependencies/glfw-3.3/examples/offscreen: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable offscreen"
	cd "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/offscreen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/build: dependencies/glfw-3.3/examples/offscreen

.PHONY : dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/build

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/requires: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/offscreen.c.o.requires
dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/requires: dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o.requires

.PHONY : dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/requires

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/clean:
	cd "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" && $(CMAKE_COMMAND) -P CMakeFiles/offscreen.dir/cmake_clean.cmake
.PHONY : dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/clean

dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/depend:
	cd "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw" "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw" "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples" "/home/ramzisah/Desktop/Cpp/openGL/#3 test glfw/dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : dependencies/glfw-3.3/examples/CMakeFiles/offscreen.dir/depend
