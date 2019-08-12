# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matteo/CLionProjects/Project_Alpha

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matteo/CLionProjects/Project_Alpha

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/opt/clion-2019.1.3/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/clion-2019.1.3/bin/cmake/linux/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/matteo/CLionProjects/Project_Alpha/CMakeFiles /home/matteo/CLionProjects/Project_Alpha/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/matteo/CLionProjects/Project_Alpha/CMakeFiles 0
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
# Target rules for targets named Project_Alpha

# Build rule for target.
Project_Alpha: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Project_Alpha
.PHONY : Project_Alpha

# fast build rule for target.
Project_Alpha/fast:
	$(MAKE) -f CMakeFiles/Project_Alpha.dir/build.make CMakeFiles/Project_Alpha.dir/build
.PHONY : Project_Alpha/fast

#=============================================================================
# Target rules for targets named core

# Build rule for target.
core: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 core
.PHONY : core

# fast build rule for target.
core/fast:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/build
.PHONY : core/fast

#=============================================================================
# Target rules for targets named runGameTests

# Build rule for target.
runGameTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runGameTests
.PHONY : runGameTests

# fast build rule for target.
runGameTests/fast:
	$(MAKE) -f Project_Alpha/test/CMakeFiles/runGameTests.dir/build.make Project_Alpha/test/CMakeFiles/runGameTests.dir/build
.PHONY : runGameTests/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) -f Project_Alpha/test/lib/googletest/CMakeFiles/gtest.dir/build.make Project_Alpha/test/lib/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) -f Project_Alpha/test/lib/googletest/CMakeFiles/gtest_main.dir/build.make Project_Alpha/test/lib/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

Project_Alpha/Archer.o: Project_Alpha/Archer.cpp.o

.PHONY : Project_Alpha/Archer.o

# target to build an object file
Project_Alpha/Archer.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Archer.cpp.o
.PHONY : Project_Alpha/Archer.cpp.o

Project_Alpha/Archer.i: Project_Alpha/Archer.cpp.i

.PHONY : Project_Alpha/Archer.i

# target to preprocess a source file
Project_Alpha/Archer.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Archer.cpp.i
.PHONY : Project_Alpha/Archer.cpp.i

Project_Alpha/Archer.s: Project_Alpha/Archer.cpp.s

.PHONY : Project_Alpha/Archer.s

# target to generate assembly for a file
Project_Alpha/Archer.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Archer.cpp.s
.PHONY : Project_Alpha/Archer.cpp.s

Project_Alpha/Boss.o: Project_Alpha/Boss.cpp.o

.PHONY : Project_Alpha/Boss.o

# target to build an object file
Project_Alpha/Boss.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Boss.cpp.o
.PHONY : Project_Alpha/Boss.cpp.o

Project_Alpha/Boss.i: Project_Alpha/Boss.cpp.i

.PHONY : Project_Alpha/Boss.i

# target to preprocess a source file
Project_Alpha/Boss.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Boss.cpp.i
.PHONY : Project_Alpha/Boss.cpp.i

Project_Alpha/Boss.s: Project_Alpha/Boss.cpp.s

.PHONY : Project_Alpha/Boss.s

# target to generate assembly for a file
Project_Alpha/Boss.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Boss.cpp.s
.PHONY : Project_Alpha/Boss.cpp.s

Project_Alpha/Chest.o: Project_Alpha/Chest.cpp.o

.PHONY : Project_Alpha/Chest.o

# target to build an object file
Project_Alpha/Chest.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Chest.cpp.o
.PHONY : Project_Alpha/Chest.cpp.o

Project_Alpha/Chest.i: Project_Alpha/Chest.cpp.i

.PHONY : Project_Alpha/Chest.i

# target to preprocess a source file
Project_Alpha/Chest.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Chest.cpp.i
.PHONY : Project_Alpha/Chest.cpp.i

Project_Alpha/Chest.s: Project_Alpha/Chest.cpp.s

.PHONY : Project_Alpha/Chest.s

# target to generate assembly for a file
Project_Alpha/Chest.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Chest.cpp.s
.PHONY : Project_Alpha/Chest.cpp.s

Project_Alpha/Enemy.o: Project_Alpha/Enemy.cpp.o

.PHONY : Project_Alpha/Enemy.o

# target to build an object file
Project_Alpha/Enemy.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Enemy.cpp.o
.PHONY : Project_Alpha/Enemy.cpp.o

Project_Alpha/Enemy.i: Project_Alpha/Enemy.cpp.i

.PHONY : Project_Alpha/Enemy.i

# target to preprocess a source file
Project_Alpha/Enemy.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Enemy.cpp.i
.PHONY : Project_Alpha/Enemy.cpp.i

Project_Alpha/Enemy.s: Project_Alpha/Enemy.cpp.s

.PHONY : Project_Alpha/Enemy.s

# target to generate assembly for a file
Project_Alpha/Enemy.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Enemy.cpp.s
.PHONY : Project_Alpha/Enemy.cpp.s

Project_Alpha/GameCharacter.o: Project_Alpha/GameCharacter.cpp.o

.PHONY : Project_Alpha/GameCharacter.o

# target to build an object file
Project_Alpha/GameCharacter.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/GameCharacter.cpp.o
.PHONY : Project_Alpha/GameCharacter.cpp.o

Project_Alpha/GameCharacter.i: Project_Alpha/GameCharacter.cpp.i

.PHONY : Project_Alpha/GameCharacter.i

# target to preprocess a source file
Project_Alpha/GameCharacter.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/GameCharacter.cpp.i
.PHONY : Project_Alpha/GameCharacter.cpp.i

Project_Alpha/GameCharacter.s: Project_Alpha/GameCharacter.cpp.s

.PHONY : Project_Alpha/GameCharacter.s

# target to generate assembly for a file
Project_Alpha/GameCharacter.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/GameCharacter.cpp.s
.PHONY : Project_Alpha/GameCharacter.cpp.s

Project_Alpha/Hero.o: Project_Alpha/Hero.cpp.o

.PHONY : Project_Alpha/Hero.o

# target to build an object file
Project_Alpha/Hero.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Hero.cpp.o
.PHONY : Project_Alpha/Hero.cpp.o

Project_Alpha/Hero.i: Project_Alpha/Hero.cpp.i

.PHONY : Project_Alpha/Hero.i

# target to preprocess a source file
Project_Alpha/Hero.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Hero.cpp.i
.PHONY : Project_Alpha/Hero.cpp.i

Project_Alpha/Hero.s: Project_Alpha/Hero.cpp.s

.PHONY : Project_Alpha/Hero.s

# target to generate assembly for a file
Project_Alpha/Hero.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Hero.cpp.s
.PHONY : Project_Alpha/Hero.cpp.s

Project_Alpha/Item.o: Project_Alpha/Item.cpp.o

.PHONY : Project_Alpha/Item.o

# target to build an object file
Project_Alpha/Item.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Item.cpp.o
.PHONY : Project_Alpha/Item.cpp.o

Project_Alpha/Item.i: Project_Alpha/Item.cpp.i

.PHONY : Project_Alpha/Item.i

# target to preprocess a source file
Project_Alpha/Item.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Item.cpp.i
.PHONY : Project_Alpha/Item.cpp.i

Project_Alpha/Item.s: Project_Alpha/Item.cpp.s

.PHONY : Project_Alpha/Item.s

# target to generate assembly for a file
Project_Alpha/Item.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Item.cpp.s
.PHONY : Project_Alpha/Item.cpp.s

Project_Alpha/Knight.o: Project_Alpha/Knight.cpp.o

.PHONY : Project_Alpha/Knight.o

# target to build an object file
Project_Alpha/Knight.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Knight.cpp.o
.PHONY : Project_Alpha/Knight.cpp.o

Project_Alpha/Knight.i: Project_Alpha/Knight.cpp.i

.PHONY : Project_Alpha/Knight.i

# target to preprocess a source file
Project_Alpha/Knight.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Knight.cpp.i
.PHONY : Project_Alpha/Knight.cpp.i

Project_Alpha/Knight.s: Project_Alpha/Knight.cpp.s

.PHONY : Project_Alpha/Knight.s

# target to generate assembly for a file
Project_Alpha/Knight.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Knight.cpp.s
.PHONY : Project_Alpha/Knight.cpp.s

Project_Alpha/Mage.o: Project_Alpha/Mage.cpp.o

.PHONY : Project_Alpha/Mage.o

# target to build an object file
Project_Alpha/Mage.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Mage.cpp.o
.PHONY : Project_Alpha/Mage.cpp.o

Project_Alpha/Mage.i: Project_Alpha/Mage.cpp.i

.PHONY : Project_Alpha/Mage.i

# target to preprocess a source file
Project_Alpha/Mage.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Mage.cpp.i
.PHONY : Project_Alpha/Mage.cpp.i

Project_Alpha/Mage.s: Project_Alpha/Mage.cpp.s

.PHONY : Project_Alpha/Mage.s

# target to generate assembly for a file
Project_Alpha/Mage.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Mage.cpp.s
.PHONY : Project_Alpha/Mage.cpp.s

Project_Alpha/Map.o: Project_Alpha/Map.cpp.o

.PHONY : Project_Alpha/Map.o

# target to build an object file
Project_Alpha/Map.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Map.cpp.o
.PHONY : Project_Alpha/Map.cpp.o

Project_Alpha/Map.i: Project_Alpha/Map.cpp.i

.PHONY : Project_Alpha/Map.i

# target to preprocess a source file
Project_Alpha/Map.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Map.cpp.i
.PHONY : Project_Alpha/Map.cpp.i

Project_Alpha/Map.s: Project_Alpha/Map.cpp.s

.PHONY : Project_Alpha/Map.s

# target to generate assembly for a file
Project_Alpha/Map.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Map.cpp.s
.PHONY : Project_Alpha/Map.cpp.s

Project_Alpha/Tile.o: Project_Alpha/Tile.cpp.o

.PHONY : Project_Alpha/Tile.o

# target to build an object file
Project_Alpha/Tile.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Tile.cpp.o
.PHONY : Project_Alpha/Tile.cpp.o

Project_Alpha/Tile.i: Project_Alpha/Tile.cpp.i

.PHONY : Project_Alpha/Tile.i

# target to preprocess a source file
Project_Alpha/Tile.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Tile.cpp.i
.PHONY : Project_Alpha/Tile.cpp.i

Project_Alpha/Tile.s: Project_Alpha/Tile.cpp.s

.PHONY : Project_Alpha/Tile.s

# target to generate assembly for a file
Project_Alpha/Tile.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Tile.cpp.s
.PHONY : Project_Alpha/Tile.cpp.s

Project_Alpha/Weapon.o: Project_Alpha/Weapon.cpp.o

.PHONY : Project_Alpha/Weapon.o

# target to build an object file
Project_Alpha/Weapon.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Weapon.cpp.o
.PHONY : Project_Alpha/Weapon.cpp.o

Project_Alpha/Weapon.i: Project_Alpha/Weapon.cpp.i

.PHONY : Project_Alpha/Weapon.i

# target to preprocess a source file
Project_Alpha/Weapon.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Weapon.cpp.i
.PHONY : Project_Alpha/Weapon.cpp.i

Project_Alpha/Weapon.s: Project_Alpha/Weapon.cpp.s

.PHONY : Project_Alpha/Weapon.s

# target to generate assembly for a file
Project_Alpha/Weapon.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Project_Alpha/Weapon.cpp.s
.PHONY : Project_Alpha/Weapon.cpp.s

Project_Alpha/main.o: Project_Alpha/main.cpp.o

.PHONY : Project_Alpha/main.o

# target to build an object file
Project_Alpha/main.cpp.o:
	$(MAKE) -f CMakeFiles/Project_Alpha.dir/build.make CMakeFiles/Project_Alpha.dir/Project_Alpha/main.cpp.o
.PHONY : Project_Alpha/main.cpp.o

Project_Alpha/main.i: Project_Alpha/main.cpp.i

.PHONY : Project_Alpha/main.i

# target to preprocess a source file
Project_Alpha/main.cpp.i:
	$(MAKE) -f CMakeFiles/Project_Alpha.dir/build.make CMakeFiles/Project_Alpha.dir/Project_Alpha/main.cpp.i
.PHONY : Project_Alpha/main.cpp.i

Project_Alpha/main.s: Project_Alpha/main.cpp.s

.PHONY : Project_Alpha/main.s

# target to generate assembly for a file
Project_Alpha/main.cpp.s:
	$(MAKE) -f CMakeFiles/Project_Alpha.dir/build.make CMakeFiles/Project_Alpha.dir/Project_Alpha/main.cpp.s
.PHONY : Project_Alpha/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... Project_Alpha"
	@echo "... rebuild_cache"
	@echo "... core"
	@echo "... runGameTests"
	@echo "... gtest"
	@echo "... gtest_main"
	@echo "... Project_Alpha/Archer.o"
	@echo "... Project_Alpha/Archer.i"
	@echo "... Project_Alpha/Archer.s"
	@echo "... Project_Alpha/Boss.o"
	@echo "... Project_Alpha/Boss.i"
	@echo "... Project_Alpha/Boss.s"
	@echo "... Project_Alpha/Chest.o"
	@echo "... Project_Alpha/Chest.i"
	@echo "... Project_Alpha/Chest.s"
	@echo "... Project_Alpha/Enemy.o"
	@echo "... Project_Alpha/Enemy.i"
	@echo "... Project_Alpha/Enemy.s"
	@echo "... Project_Alpha/GameCharacter.o"
	@echo "... Project_Alpha/GameCharacter.i"
	@echo "... Project_Alpha/GameCharacter.s"
	@echo "... Project_Alpha/Hero.o"
	@echo "... Project_Alpha/Hero.i"
	@echo "... Project_Alpha/Hero.s"
	@echo "... Project_Alpha/Item.o"
	@echo "... Project_Alpha/Item.i"
	@echo "... Project_Alpha/Item.s"
	@echo "... Project_Alpha/Knight.o"
	@echo "... Project_Alpha/Knight.i"
	@echo "... Project_Alpha/Knight.s"
	@echo "... Project_Alpha/Mage.o"
	@echo "... Project_Alpha/Mage.i"
	@echo "... Project_Alpha/Mage.s"
	@echo "... Project_Alpha/Map.o"
	@echo "... Project_Alpha/Map.i"
	@echo "... Project_Alpha/Map.s"
	@echo "... Project_Alpha/Tile.o"
	@echo "... Project_Alpha/Tile.i"
	@echo "... Project_Alpha/Tile.s"
	@echo "... Project_Alpha/Weapon.o"
	@echo "... Project_Alpha/Weapon.i"
	@echo "... Project_Alpha/Weapon.s"
	@echo "... Project_Alpha/main.o"
	@echo "... Project_Alpha/main.i"
	@echo "... Project_Alpha/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
