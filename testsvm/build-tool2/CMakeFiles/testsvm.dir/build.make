# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/liyang/worktree2018/testsvm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liyang/worktree2018/testsvm/build-tool2

# Include any dependencies generated for this target.
include CMakeFiles/testsvm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testsvm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testsvm.dir/flags.make

CMakeFiles/testsvm.dir/testsvm.cpp.o: CMakeFiles/testsvm.dir/flags.make
CMakeFiles/testsvm.dir/testsvm.cpp.o: ../testsvm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liyang/worktree2018/testsvm/build-tool2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testsvm.dir/testsvm.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testsvm.dir/testsvm.cpp.o -c /home/liyang/worktree2018/testsvm/testsvm.cpp

CMakeFiles/testsvm.dir/testsvm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testsvm.dir/testsvm.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liyang/worktree2018/testsvm/testsvm.cpp > CMakeFiles/testsvm.dir/testsvm.cpp.i

CMakeFiles/testsvm.dir/testsvm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testsvm.dir/testsvm.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liyang/worktree2018/testsvm/testsvm.cpp -o CMakeFiles/testsvm.dir/testsvm.cpp.s

CMakeFiles/testsvm.dir/testsvm.cpp.o.requires:

.PHONY : CMakeFiles/testsvm.dir/testsvm.cpp.o.requires

CMakeFiles/testsvm.dir/testsvm.cpp.o.provides: CMakeFiles/testsvm.dir/testsvm.cpp.o.requires
	$(MAKE) -f CMakeFiles/testsvm.dir/build.make CMakeFiles/testsvm.dir/testsvm.cpp.o.provides.build
.PHONY : CMakeFiles/testsvm.dir/testsvm.cpp.o.provides

CMakeFiles/testsvm.dir/testsvm.cpp.o.provides.build: CMakeFiles/testsvm.dir/testsvm.cpp.o


CMakeFiles/testsvm.dir/main.cpp.o: CMakeFiles/testsvm.dir/flags.make
CMakeFiles/testsvm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liyang/worktree2018/testsvm/build-tool2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testsvm.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testsvm.dir/main.cpp.o -c /home/liyang/worktree2018/testsvm/main.cpp

CMakeFiles/testsvm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testsvm.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liyang/worktree2018/testsvm/main.cpp > CMakeFiles/testsvm.dir/main.cpp.i

CMakeFiles/testsvm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testsvm.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liyang/worktree2018/testsvm/main.cpp -o CMakeFiles/testsvm.dir/main.cpp.s

CMakeFiles/testsvm.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/testsvm.dir/main.cpp.o.requires

CMakeFiles/testsvm.dir/main.cpp.o.provides: CMakeFiles/testsvm.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/testsvm.dir/build.make CMakeFiles/testsvm.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/testsvm.dir/main.cpp.o.provides

CMakeFiles/testsvm.dir/main.cpp.o.provides.build: CMakeFiles/testsvm.dir/main.cpp.o


CMakeFiles/testsvm.dir/wxzSVM.cpp.o: CMakeFiles/testsvm.dir/flags.make
CMakeFiles/testsvm.dir/wxzSVM.cpp.o: ../wxzSVM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liyang/worktree2018/testsvm/build-tool2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/testsvm.dir/wxzSVM.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testsvm.dir/wxzSVM.cpp.o -c /home/liyang/worktree2018/testsvm/wxzSVM.cpp

CMakeFiles/testsvm.dir/wxzSVM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testsvm.dir/wxzSVM.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liyang/worktree2018/testsvm/wxzSVM.cpp > CMakeFiles/testsvm.dir/wxzSVM.cpp.i

CMakeFiles/testsvm.dir/wxzSVM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testsvm.dir/wxzSVM.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liyang/worktree2018/testsvm/wxzSVM.cpp -o CMakeFiles/testsvm.dir/wxzSVM.cpp.s

CMakeFiles/testsvm.dir/wxzSVM.cpp.o.requires:

.PHONY : CMakeFiles/testsvm.dir/wxzSVM.cpp.o.requires

CMakeFiles/testsvm.dir/wxzSVM.cpp.o.provides: CMakeFiles/testsvm.dir/wxzSVM.cpp.o.requires
	$(MAKE) -f CMakeFiles/testsvm.dir/build.make CMakeFiles/testsvm.dir/wxzSVM.cpp.o.provides.build
.PHONY : CMakeFiles/testsvm.dir/wxzSVM.cpp.o.provides

CMakeFiles/testsvm.dir/wxzSVM.cpp.o.provides.build: CMakeFiles/testsvm.dir/wxzSVM.cpp.o


# Object files for target testsvm
testsvm_OBJECTS = \
"CMakeFiles/testsvm.dir/testsvm.cpp.o" \
"CMakeFiles/testsvm.dir/main.cpp.o" \
"CMakeFiles/testsvm.dir/wxzSVM.cpp.o"

# External object files for target testsvm
testsvm_EXTERNAL_OBJECTS =

sdk/bin/testsvm: CMakeFiles/testsvm.dir/testsvm.cpp.o
sdk/bin/testsvm: CMakeFiles/testsvm.dir/main.cpp.o
sdk/bin/testsvm: CMakeFiles/testsvm.dir/wxzSVM.cpp.o
sdk/bin/testsvm: CMakeFiles/testsvm.dir/build.make
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalvision.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalextractor.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalthread.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalproxies.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalcommon.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_signals.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/librttools.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalvalue.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalerror.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libqimessaging.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libqitype.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libqi.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_chrono.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_filesystem.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_program_options.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_regex.so
sdk/bin/testsvm: /usr/lib/x86_64-linux-gnu/libdl.so
sdk/bin/testsvm: /usr/lib/x86_64-linux-gnu/librt.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_date_time.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_system.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_locale.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_thread.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libopencv_world.so
sdk/bin/testsvm: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libz.so
sdk/bin/testsvm: CMakeFiles/testsvm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liyang/worktree2018/testsvm/build-tool2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable sdk/bin/testsvm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testsvm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testsvm.dir/build: sdk/bin/testsvm

.PHONY : CMakeFiles/testsvm.dir/build

CMakeFiles/testsvm.dir/requires: CMakeFiles/testsvm.dir/testsvm.cpp.o.requires
CMakeFiles/testsvm.dir/requires: CMakeFiles/testsvm.dir/main.cpp.o.requires
CMakeFiles/testsvm.dir/requires: CMakeFiles/testsvm.dir/wxzSVM.cpp.o.requires

.PHONY : CMakeFiles/testsvm.dir/requires

CMakeFiles/testsvm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testsvm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testsvm.dir/clean

CMakeFiles/testsvm.dir/depend:
	cd /home/liyang/worktree2018/testsvm/build-tool2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liyang/worktree2018/testsvm /home/liyang/worktree2018/testsvm /home/liyang/worktree2018/testsvm/build-tool2 /home/liyang/worktree2018/testsvm/build-tool2 /home/liyang/worktree2018/testsvm/build-tool2/CMakeFiles/testsvm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testsvm.dir/depend

