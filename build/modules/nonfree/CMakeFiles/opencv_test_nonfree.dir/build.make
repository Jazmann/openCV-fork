# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /opt/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jaspershemilt/Developer/openCV_Dev/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jaspershemilt/Developer/openCV_Dev/opencv/build

# Include any dependencies generated for this target.
include modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/depend.make

# Include the progress variables for this target.
include modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/progress.make

# Include the compile flags for this target's objects.
include modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/flags.make

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/flags.make
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o: ../modules/nonfree/test/test_detectors.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o -c /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_detectors.cpp

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.i"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_detectors.cpp > CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.i

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.s"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_detectors.cpp -o CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.s

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o.requires:
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o.requires

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o.provides: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o.requires
	$(MAKE) -f modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/build.make modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o.provides.build
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o.provides

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o.provides.build: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/flags.make
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o: ../modules/nonfree/test/test_features2d.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o -c /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_features2d.cpp

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.i"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_features2d.cpp > CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.i

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.s"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_features2d.cpp -o CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.s

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o.requires:
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o.requires

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o.provides: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o.requires
	$(MAKE) -f modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/build.make modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o.provides.build
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o.provides

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o.provides.build: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/flags.make
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o: ../modules/nonfree/test/test_keypoints.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o -c /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_keypoints.cpp

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.i"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_keypoints.cpp > CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.i

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.s"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_keypoints.cpp -o CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.s

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o.requires:
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o.requires

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o.provides: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o.requires
	$(MAKE) -f modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/build.make modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o.provides.build
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o.provides

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o.provides.build: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/flags.make
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o: ../modules/nonfree/test/test_main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o -c /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_main.cpp

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.i"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_main.cpp > CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.i

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.s"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_main.cpp -o CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.s

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o.requires:
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o.requires

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o.provides: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o.requires
	$(MAKE) -f modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/build.make modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o.provides.build
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o.provides

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o.provides.build: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/flags.make
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o: ../modules/nonfree/test/test_precomp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o -c /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_precomp.cpp

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.i"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_precomp.cpp > CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.i

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.s"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_precomp.cpp -o CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.s

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o.requires:
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o.requires

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o.provides: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o.requires
	$(MAKE) -f modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/build.make modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o.provides.build
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o.provides

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o.provides.build: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/flags.make
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o: ../modules/nonfree/test/test_rotation_and_scale_invariance.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o -c /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_rotation_and_scale_invariance.cpp

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.i"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_rotation_and_scale_invariance.cpp > CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.i

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.s"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree/test/test_rotation_and_scale_invariance.cpp -o CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.s

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o.requires:
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o.requires

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o.provides: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o.requires
	$(MAKE) -f modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/build.make modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o.provides.build
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o.provides

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o.provides.build: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o

# Object files for target opencv_test_nonfree
opencv_test_nonfree_OBJECTS = \
"CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o" \
"CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o" \
"CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o" \
"CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o" \
"CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o" \
"CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o"

# External object files for target opencv_test_nonfree
opencv_test_nonfree_EXTERNAL_OBJECTS =

bin/opencv_test_nonfree: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o
bin/opencv_test_nonfree: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o
bin/opencv_test_nonfree: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o
bin/opencv_test_nonfree: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o
bin/opencv_test_nonfree: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o
bin/opencv_test_nonfree: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o
bin/opencv_test_nonfree: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/build.make
bin/opencv_test_nonfree: lib/libopencv_core.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_imgproc.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_flann.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_highgui.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_features2d.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_nonfree.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_ts.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_highgui.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_core.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_imgproc.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_flann.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_highgui.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_features2d.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_flann.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_highgui.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_imgproc.2.4.2.dylib
bin/opencv_test_nonfree: lib/libopencv_core.2.4.2.dylib
bin/opencv_test_nonfree: 3rdparty/lib/libzlib.a
bin/opencv_test_nonfree: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/opencv_test_nonfree"
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_test_nonfree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/build: bin/opencv_test_nonfree
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/build

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/requires: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_detectors.cpp.o.requires
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/requires: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_features2d.cpp.o.requires
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/requires: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_keypoints.cpp.o.requires
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/requires: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_main.cpp.o.requires
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/requires: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_precomp.cpp.o.requires
modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/requires: modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/test/test_rotation_and_scale_invariance.cpp.o.requires
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/requires

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/clean:
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree && $(CMAKE_COMMAND) -P CMakeFiles/opencv_test_nonfree.dir/cmake_clean.cmake
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/clean

modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/depend:
	cd /Users/jaspershemilt/Developer/openCV_Dev/opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaspershemilt/Developer/openCV_Dev/opencv /Users/jaspershemilt/Developer/openCV_Dev/opencv/modules/nonfree /Users/jaspershemilt/Developer/openCV_Dev/opencv/build /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree /Users/jaspershemilt/Developer/openCV_Dev/opencv/build/modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/nonfree/CMakeFiles/opencv_test_nonfree.dir/depend

