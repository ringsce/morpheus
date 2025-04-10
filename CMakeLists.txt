cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

if(POLICY CMP0092)
    cmake_policy(SET CMP0092 NEW)
endif()

if(POLICY CMP0114)
    cmake_policy(SET CMP0114 NEW)
endif()

# Load platform-specific toolchains if not already set externally
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
        set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain/macos-silicon-toolchain.cmake" CACHE FILEPATH "" FORCE)
        set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain/ios-arm64-toolchain.cmake" CACHE FILEPATH "" FORCE)
    elseif(WIN32 AND CMAKE_SYSTEM_PROCESSOR MATCHES "ARM64")
        set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain/windows-arm64-toolchain.cmake" CACHE FILEPATH "" FORCE)
    elseif(UNIX AND CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
        set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain/linux-arm64-toolchain.cmake" CACHE FILEPATH "" FORCE)
    endif()
endif()


# macOS Deployment Target
set(MACOS_SUPPORT_MINIMUM 11.7.1)
if(NOT CMAKE_OSX_DEPLOYMENT_TARGET)
    set(CMAKE_OSX_DEPLOYMENT_TARGET ${MACOS_SUPPORT_MINIMUM}
        CACHE STRING "Minimum macOS version to target for deployment"
        FORCE)
endif()

project(neon LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Platform Detection
if(APPLE)
    message(STATUS "Configuring for macOS")
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
        set(MACOS_SILICON TRUE)
        message(STATUS "Target: macOS ARM64 (Silicon)")
    else()
        message(STATUS "Target: Intel macOS")
    endif()

elseif(UNIX AND NOT APPLE)
    message(STATUS "Configuring for Linux")
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
        set(LINUX_ARM64 TRUE)
        message(STATUS "Target: Linux ARM64")
    endif()

elseif(WIN32)
    message(STATUS "Configuring for Windows")
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "ARM64")
        set(WINDOWS_ARM64 TRUE)
        message(STATUS "Target: Windows 11 ARM64")
    else()
        message(STATUS "Target: Windows 11 AMD64")
    endif()

elseif(ANDROID)
    message(STATUS "Configuring for Android")
    set(ANDROID TRUE)

elseif(IOS)
    message(STATUS "Configuring for iOS")
    set(IOS TRUE)

else()
    message(STATUS "Unsupported platform")
endif()

# GTK on supported systems
if(NOT ANDROID AND NOT IOS AND NOT WIN32)
    add_subdirectory(gtk)
endif()

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets)

# Compiler standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# macOS Icon
set(ICONSET_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources/icon.iconset")
set(ICON_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/resources")
set(ICNS_FILE "${ICON_OUTPUT_DIR}/icon.icns")

add_custom_command(
    OUTPUT ${ICNS_FILE}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${ICON_OUTPUT_DIR}
    COMMAND iconutil -c icns "${ICONSET_DIR}" -o "${ICNS_FILE}"
    DEPENDS ${ICONSET_DIR}
    COMMENT "Generating .icns icon from .iconset"
    VERBATIM
)

add_custom_target(generate_icns ALL DEPENDS ${ICNS_FILE})

# Attach generated icon to your macOS bundle
set_source_files_properties(${ICNS_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
set(MACOSX_BUNDLE_ICON_FILE icon.icns)

# Add icon to app target
add_dependencies(neon generate_icns)
target_sources(neon PRIVATE ${ICNS_FILE})
set(MACOSX_BUNDLE_ICON_FILE icon.icns)
set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/resources/icon.icns")
set_source_files_properties(${app_icon_macos} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

# Executable
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

# Set bundle for macOS
set_target_properties(neon PROPERTIES MACOSX_BUNDLE TRUE)

# Link Qt and GTK if applicable
target_link_libraries(neon PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Network
    Qt::Widgets
)

if(NOT WIN32 AND NOT ANDROID AND NOT IOS)
    target_link_libraries(neon PUBLIC PkgConfig::GTK4)
endif()

# Icons
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

qt_add_resources(neon "icons"
    PREFIX "/"
    FILES ${icons_resource_files}
)

# Android specific
if(ANDROID)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/android-arm64-toolchain.cmake")
    set(CMAKE_ANDROID_NDK "/path/to/your/ndk")
    set(CMAKE_ANDROID_STL_TYPE "c++_static")
    set(CMAKE_ANDROID_ARCH_ABI "arm64-v8a")
    set(CMAKE_ANDROID_NATIVE_API_LEVEL 21)
    set(CMAKE_ANDROID_SDK "/path/to/your/sdk")

# iOS specific
elseif(IOS)
    set(CMAKE_IOS_DEPLOYMENT_TARGET "15.0")
    set(CMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer")
    set(CMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM "YOUR_TEAM_ID")
endif()
