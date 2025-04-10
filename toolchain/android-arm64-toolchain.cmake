# Used automatically with ANDROID_NDK's toolchain in CMakePresets
set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION 21)
set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)

# Set NDK path manually if not using environment variable
# set(ANDROID_NDK /path/to/android-ndk)

set(CMAKE_ANDROID_STL_TYPE c++_static)
