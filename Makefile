# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /mnt/d/r/code/FUN/GenExample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/r/code/FUN/GenExample

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/r/code/FUN/GenExample/CMakeFiles /mnt/d/r/code/FUN/GenExample/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/r/code/FUN/GenExample/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named GenSpeed

# Build rule for target.
GenSpeed: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 GenSpeed
.PHONY : GenSpeed

# fast build rule for target.
GenSpeed/fast:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/build
.PHONY : GenSpeed/fast

generationByCubitect/finders.o: generationByCubitect/finders.c.o

.PHONY : generationByCubitect/finders.o

# target to build an object file
generationByCubitect/finders.c.o:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/generationByCubitect/finders.c.o
.PHONY : generationByCubitect/finders.c.o

generationByCubitect/finders.i: generationByCubitect/finders.c.i

.PHONY : generationByCubitect/finders.i

# target to preprocess a source file
generationByCubitect/finders.c.i:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/generationByCubitect/finders.c.i
.PHONY : generationByCubitect/finders.c.i

generationByCubitect/finders.s: generationByCubitect/finders.c.s

.PHONY : generationByCubitect/finders.s

# target to generate assembly for a file
generationByCubitect/finders.c.s:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/generationByCubitect/finders.c.s
.PHONY : generationByCubitect/finders.c.s

generationByCubitect/generator.o: generationByCubitect/generator.c.o

.PHONY : generationByCubitect/generator.o

# target to build an object file
generationByCubitect/generator.c.o:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/generationByCubitect/generator.c.o
.PHONY : generationByCubitect/generator.c.o

generationByCubitect/generator.i: generationByCubitect/generator.c.i

.PHONY : generationByCubitect/generator.i

# target to preprocess a source file
generationByCubitect/generator.c.i:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/generationByCubitect/generator.c.i
.PHONY : generationByCubitect/generator.c.i

generationByCubitect/generator.s: generationByCubitect/generator.c.s

.PHONY : generationByCubitect/generator.s

# target to generate assembly for a file
generationByCubitect/generator.c.s:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/generationByCubitect/generator.c.s
.PHONY : generationByCubitect/generator.c.s

generationByCubitect/layers.o: generationByCubitect/layers.c.o

.PHONY : generationByCubitect/layers.o

# target to build an object file
generationByCubitect/layers.c.o:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/generationByCubitect/layers.c.o
.PHONY : generationByCubitect/layers.c.o

generationByCubitect/layers.i: generationByCubitect/layers.c.i

.PHONY : generationByCubitect/layers.i

# target to preprocess a source file
generationByCubitect/layers.c.i:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/generationByCubitect/layers.c.i
.PHONY : generationByCubitect/layers.c.i

generationByCubitect/layers.s: generationByCubitect/layers.c.s

.PHONY : generationByCubitect/layers.s

# target to generate assembly for a file
generationByCubitect/layers.c.s:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/generationByCubitect/layers.c.s
.PHONY : generationByCubitect/layers.c.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/GenSpeed.dir/build.make CMakeFiles/GenSpeed.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... GenSpeed"
	@echo "... generationByCubitect/finders.o"
	@echo "... generationByCubitect/finders.i"
	@echo "... generationByCubitect/finders.s"
	@echo "... generationByCubitect/generator.o"
	@echo "... generationByCubitect/generator.i"
	@echo "... generationByCubitect/generator.s"
	@echo "... generationByCubitect/layers.o"
	@echo "... generationByCubitect/layers.i"
	@echo "... generationByCubitect/layers.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

