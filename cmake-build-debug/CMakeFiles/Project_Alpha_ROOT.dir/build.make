# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matteo/CLionProjects/Project_Alpha

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matteo/CLionProjects/Project_Alpha/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project_Alpha_ROOT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_Alpha_ROOT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_Alpha_ROOT.dir/flags.make

CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.o: ../GameManager/AssetManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameManager/AssetManager.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameManager/AssetManager.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameManager/AssetManager.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.o: ../GameManager/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameManager/Game.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameManager/Game.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameManager/Game.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.o: ../GameStates/GameOverState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameStates/GameOverState.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameStates/GameOverState.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameStates/GameOverState.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.o: ../GameStates/GameState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameStates/GameState.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameStates/GameState.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameStates/GameState.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.o: ../GameManager/InputManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameManager/InputManager.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameManager/InputManager.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameManager/InputManager.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/main.cpp

CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/main.cpp > CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/main.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.o: ../GameStates/MainMenuState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameStates/MainMenuState.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameStates/MainMenuState.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameStates/MainMenuState.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.o: ../GameStates/PauseState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameStates/PauseState.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameStates/PauseState.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameStates/PauseState.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.o: ../GameStates/SplashState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameStates/SplashState.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameStates/SplashState.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameStates/SplashState.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.o: ../GameStates/StateMachine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameStates/StateMachine.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameStates/StateMachine.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameStates/StateMachine.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.o: ../GameStates/SelectClassState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameStates/SelectClassState.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameStates/SelectClassState.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameStates/SelectClassState.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.o: ../Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Map.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Map.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Map.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.o: ../Hero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Hero.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Hero.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Hero.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.o: ../GameCharacter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/GameCharacter.cpp

CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/GameCharacter.cpp > CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/GameCharacter.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.o: ../Item.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Item.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Item.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Item.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.o: ../Weapon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Weapon.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Weapon.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Weapon.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.o: ../Archer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Archer.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Archer.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Archer.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.o: ../Knight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Knight.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Knight.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Knight.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.o: ../Mage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Mage.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Mage.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Mage.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.o: ../Projectile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Projectile.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Projectile.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Projectile.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.o: ../Enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Enemy.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Enemy.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Enemy.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.o: ../Random.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Random.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Random.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Random.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.s

CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.o: CMakeFiles/Project_Alpha_ROOT.dir/flags.make
CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.o: ../Classes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Building CXX object CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.o -c /home/matteo/CLionProjects/Project_Alpha/Classes.cpp

CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/CLionProjects/Project_Alpha/Classes.cpp > CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.i

CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/CLionProjects/Project_Alpha/Classes.cpp -o CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.s

# Object files for target Project_Alpha_ROOT
Project_Alpha_ROOT_OBJECTS = \
"CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.o" \
"CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.o"

# External object files for target Project_Alpha_ROOT
Project_Alpha_ROOT_EXTERNAL_OBJECTS =

Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameManager/AssetManager.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameManager/Game.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameOverState.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameStates/GameState.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameManager/InputManager.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/main.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameStates/MainMenuState.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameStates/PauseState.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SplashState.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameStates/StateMachine.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameStates/SelectClassState.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Map.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Hero.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/GameCharacter.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Item.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Weapon.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Archer.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Knight.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Mage.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Projectile.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Enemy.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Random.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/Classes.cpp.o
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/build.make
Project_Alpha_ROOT: /opt/SFML-2.5.1/lib/libsfml-graphics.so.2.5.1
Project_Alpha_ROOT: /opt/SFML-2.5.1/lib/libsfml-window.so.2.5.1
Project_Alpha_ROOT: /opt/SFML-2.5.1/lib/libsfml-system.so.2.5.1
Project_Alpha_ROOT: CMakeFiles/Project_Alpha_ROOT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_24) "Linking CXX executable Project_Alpha_ROOT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project_Alpha_ROOT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_Alpha_ROOT.dir/build: Project_Alpha_ROOT

.PHONY : CMakeFiles/Project_Alpha_ROOT.dir/build

CMakeFiles/Project_Alpha_ROOT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project_Alpha_ROOT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project_Alpha_ROOT.dir/clean

CMakeFiles/Project_Alpha_ROOT.dir/depend:
	cd /home/matteo/CLionProjects/Project_Alpha/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matteo/CLionProjects/Project_Alpha /home/matteo/CLionProjects/Project_Alpha /home/matteo/CLionProjects/Project_Alpha/cmake-build-debug /home/matteo/CLionProjects/Project_Alpha/cmake-build-debug /home/matteo/CLionProjects/Project_Alpha/cmake-build-debug/CMakeFiles/Project_Alpha_ROOT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project_Alpha_ROOT.dir/depend

