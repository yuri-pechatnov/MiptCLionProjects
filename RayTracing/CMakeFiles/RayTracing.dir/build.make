# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/ura/ClionProjects/RayTracing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ura/ClionProjects/RayTracing

# Include any dependencies generated for this target.
include CMakeFiles/RayTracing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RayTracing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RayTracing.dir/flags.make

CMakeFiles/RayTracing.dir/main.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/main.cpp.o -c /home/ura/ClionProjects/RayTracing/main.cpp

CMakeFiles/RayTracing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/main.cpp > CMakeFiles/RayTracing.dir/main.cpp.i

CMakeFiles/RayTracing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/main.cpp -o CMakeFiles/RayTracing.dir/main.cpp.s

CMakeFiles/RayTracing.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/main.cpp.o.requires

CMakeFiles/RayTracing.dir/main.cpp.o.provides: CMakeFiles/RayTracing.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/main.cpp.o.provides

CMakeFiles/RayTracing.dir/main.cpp.o.provides.build: CMakeFiles/RayTracing.dir/main.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o: ray_tracing/screen.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/screen.cpp

CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/screen.cpp > CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/screen.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o: ray_tracing/point.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/point.cpp

CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/point.cpp > CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/point.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o: ray_tracing/bounding_box.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/bounding_box.cpp

CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/bounding_box.cpp > CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/bounding_box.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o: ray_tracing/primitives/fig_triangle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_triangle.cpp

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_triangle.cpp > CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_triangle.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o: ray_tracing/color.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/color.cpp

CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/color.cpp > CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/color.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o: ray_tracing/ray.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/ray.cpp

CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/ray.cpp > CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/ray.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o: ray_tracing/scene.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/scene.cpp

CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/scene.cpp > CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/scene.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o: ray_tracing/fig_primitive.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/fig_primitive.cpp

CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/fig_primitive.cpp > CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/fig_primitive.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o: ray_tracing/primitives/fig_parallelogram.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_parallelogram.cpp

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_parallelogram.cpp > CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_parallelogram.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o: ray_tracing/primitives/fig_sphere.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_sphere.cpp

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_sphere.cpp > CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_sphere.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o: ray_tracing/primitives/fig_polygon.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ura/ClionProjects/RayTracing/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o -c /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_polygon.cpp

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_polygon.cpp > CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.i

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ura/ClionProjects/RayTracing/ray_tracing/primitives/fig_polygon.cpp -o CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.s

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o.requires:
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o.requires

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o.provides: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o.provides

CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o.provides.build: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o

# Object files for target RayTracing
RayTracing_OBJECTS = \
"CMakeFiles/RayTracing.dir/main.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o" \
"CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o"

# External object files for target RayTracing
RayTracing_EXTERNAL_OBJECTS =

RayTracing: CMakeFiles/RayTracing.dir/main.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/build.make
RayTracing: /usr/lib/x86_64-linux-gnu/libtiff.so
RayTracing: /usr/lib/x86_64-linux-gnu/libjpeg.so
RayTracing: /usr/lib/x86_64-linux-gnu/libz.so
RayTracing: /usr/lib/x86_64-linux-gnu/libpng.so
RayTracing: /usr/lib/x86_64-linux-gnu/libz.so
RayTracing: /usr/lib/x86_64-linux-gnu/libSM.so
RayTracing: /usr/lib/x86_64-linux-gnu/libICE.so
RayTracing: /usr/lib/x86_64-linux-gnu/libX11.so
RayTracing: /usr/lib/x86_64-linux-gnu/libXext.so
RayTracing: /usr/lib/liblapack.so.3gf
RayTracing: /usr/lib/libblas.so.3gf
RayTracing: /usr/lib/libblas.so.3gf
RayTracing: /usr/lib/x86_64-linux-gnu/libpng.so
RayTracing: /usr/lib/x86_64-linux-gnu/libSM.so
RayTracing: /usr/lib/x86_64-linux-gnu/libICE.so
RayTracing: /usr/lib/x86_64-linux-gnu/libX11.so
RayTracing: /usr/lib/x86_64-linux-gnu/libXext.so
RayTracing: /usr/lib/liblapack.so.3gf
RayTracing: /usr/lib/libblas.so.3gf
RayTracing: CMakeFiles/RayTracing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable RayTracing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RayTracing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RayTracing.dir/build: RayTracing
.PHONY : CMakeFiles/RayTracing.dir/build

CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/main.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/screen.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/point.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/bounding_box.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_triangle.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/color.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/ray.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/scene.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/fig_primitive.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_parallelogram.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_sphere.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/ray_tracing/primitives/fig_polygon.cpp.o.requires
.PHONY : CMakeFiles/RayTracing.dir/requires

CMakeFiles/RayTracing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RayTracing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RayTracing.dir/clean

CMakeFiles/RayTracing.dir/depend:
	cd /home/ura/ClionProjects/RayTracing && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ura/ClionProjects/RayTracing /home/ura/ClionProjects/RayTracing /home/ura/ClionProjects/RayTracing /home/ura/ClionProjects/RayTracing /home/ura/ClionProjects/RayTracing/CMakeFiles/RayTracing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RayTracing.dir/depend

