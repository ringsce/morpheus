# toolchain/macos-silicon-toolchain.cmake

# Set system name and processor
set(CMAKE_SYSTEM_NAME Darwin)
set(CMAKE_SYSTEM_PROCESSOR arm64)

# Deployment target for macOS ARM64
set(CMAKE_OSX_DEPLOYMENT_TARGET "11.7.1" CACHE STRING "Minimum macOS version" FORCE)

# Architectures to build
set(CMAKE_OSX_ARCHITECTURES "arm64" CACHE STRING "Build architecture" FORCE)

# C and C++ compilers (usually detected automatically, but you can override)
# set(CMAKE_C_COMPILER /opt/homebrew/bin/clang)
# set(CMAKE_CXX_COMPILER /opt/homebrew/bin/clang++)

# Find Qt6 using Homebrew or custom install path
# Uncomment and set your custom Qt path if needed:
# set(Qt6_DIR "/opt/homebrew/opt/qt6/lib/cmake/Qt6")

# Toolchain identity
message(STATUS "Using macOS Silicon (arm64) toolchain")
