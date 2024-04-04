cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

if(POLICY CMP0092)
    cmake_policy(SET CMP0092 NEW)
endif()

if(POLICY CMP0114)
    cmake_policy(SET CMP0114 NEW)
endif()

# Value should follow latest stable Xcode's RECOMMENDED_MACOSX_DEPLOYMENT_TARGET
set(MACOS_SUPPORT_MINIMUM 11.7.1)

# The value of this variable should be set prior to the first project() command invocation.
# See: https://cmake.org/cmake/help/latest/variable/CMAKE_OSX_DEPLOYMENT_TARGET.html
if(NOT CMAKE_OSX_DEPLOYMENT_TARGET)
    set(CMAKE_OSX_DEPLOYMENT_TARGET ${MACOS_SUPPORT_MINIMUM}
        CACHE STRING "Minimum macOS version to target for deployment"
        FORCE)
endif()

project(neon LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Detecting operating system
if(APPLE)
    message(STATUS "Configuring for macOS")
    # macOS specific configurations
    # You can set macOS specific variables or settings here
elseif(UNIX AND NOT APPLE)
    message(STATUS "Configuring for Linux")
    # Linux specific configurations
    # You can set Linux specific variables or settings here
elseif(WIN32)
    message(STATUS "Configuring for Windows")
    # Windows specific configurations
    # You can set Windows specific variables or settings here
endif()

# Add GTK folder
add_subdirectory(gtk)

# Find Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets)

# Set compiler standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler Warnings
set(C_WARNING_FLAGS)
set(CXX_WARNING_FLAGS)

# MACOSX_BUNDLE_ICON_FILE variable
set(MACOSX_BUNDLE_ICON_FILE icon.icns)
set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/resources/icon.icns")
set_source_files_properties(${app_icon_macos} PROPERTIES
       MACOSX_PACKAGE_LOCATION "Resources")

# Add executable
qt_add_executable(neon
    qt/addtorrentdialog.cpp qt/addtorrentdialog.h
    qt/addtorrentform.ui
    qt/bencodeparser.cpp qt/bencodeparser.h
    qt/connectionmanager.cpp qt/connectionmanager.h
    qt/filemanager.cpp qt/filemanager.h
    qt/main.cpp
    qt/mainwindow.cpp qt/mainwindow.h
    qt/metainfo.cpp qt/metainfo.h
    qt/peerwireclient.cpp qt/peerwireclient.h
    qt/ratecontroller.cpp qt/ratecontroller.h
    qt/torrentclient.cpp qt/torrentclient.h
    qt/torrentserver.cpp qt/torrentserver.h
    qt/trackerclient.cpp qt/trackerclient.h
    ${app_icon_macos} 
)

# Set properties
set_target_properties(neon PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

# Link libraries
target_link_libraries(neon PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Network
    Qt::Widgets
    PkgConfig::GTK4
)

# Resources
set(icons_resource_files
    "icons/1downarrow.png"
    "icons/1uparrow.png"
    "icons/bottom.png"
    "icons/exit.png"
    "icons/peer.png"
    "icons/player_pause.png"
    "icons/player_play.png"
    "icons/player_stop.png"
)

# Add resources
qt_add_resources(neon "icons"
    PREFIX
        "/"
    FILES
        ${icons_resource_files}
)
