# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control/build

# Utility rule file for confserver.

# Include the progress variables for this target.
include CMakeFiles/confserver.dir/progress.make

CMakeFiles/confserver:
	/home/mahesh/.espressif/python_env/idf4.2_py3.8_env/bin/python /home/mahesh/esp/esp-idf/tools/kconfig_new/prepare_kconfig_files.py --env-file /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control/build/config.env
	/home/mahesh/.espressif/python_env/idf4.2_py3.8_env/bin/python /home/mahesh/esp/esp-idf/tools/kconfig_new/confserver.py --env-file /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control/build/config.env --kconfig /home/mahesh/esp/esp-idf/Kconfig --sdkconfig-rename /home/mahesh/esp/esp-idf/sdkconfig.rename --config /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control/sdkconfig

confserver: CMakeFiles/confserver
confserver: CMakeFiles/confserver.dir/build.make

.PHONY : confserver

# Rule to build all files generated by this target.
CMakeFiles/confserver.dir/build: confserver

.PHONY : CMakeFiles/confserver.dir/build

CMakeFiles/confserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/confserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/confserver.dir/clean

CMakeFiles/confserver.dir/depend:
	cd /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control/build /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control/build /home/mahesh/Inverted-LQR-Bot-Eklavya/stepper_control/build/CMakeFiles/confserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/confserver.dir/depend

