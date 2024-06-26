# Set the name and the supported language of the project
project(neon-gtk)
# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})

# Add an executable compiled from mainwindow.cc
add_executable(neon mainwindow.cc)

# Link the target to the GTK+ libraries
target_link_libraries(neon ${GTK3_LIBRARIES})

# Detect the operating system and adjust settings accordingly
if(APPLE)
    # macOS specific settings
    # For example, you can add macOS specific flags or libraries here
    add_subdirectory(webui) # Add webui folder to build
    add_subdirectory(core) # Add core folder to build
    add_subdirectory(player) # Add player folder to build
    

elseif(UNIX AND NOT APPLE)
    # Linux specific settings
    # For example, you can add Linux specific flags or libraries here
    add_subdirectory(webui) # Add webui folder to build
    add_subdirectory(core) # Add core folder to build
    add_subdirectory(player) # Add player folder to build
    

elseif(WIN32)
    # Windows specific settings
    # For example, you can add Windows specific flags or libraries here
    add_subdirectory(webui) # Add webui folder to build
    

endif()
