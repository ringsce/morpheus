# Cross-compiling for Windows ARM64
SET(CMAKE_SYSTEM_NAME Windows)
SET(CMAKE_SYSTEM_PROCESSOR aarch64)

# Path to your cross compiler (from LLVM or MSYS2)
SET(CMAKE_C_COMPILER clang)
SET(CMAKE_CXX_COMPILER clang++)

# You can adjust these if using a custom sysroot
# SET(CMAKE_SYSROOT /path/to/sysroot)

# Optional: Add Windows SDK if needed
# SET(CMAKE_PREFIX_PATH "C:/Program Files (x86)/Windows Kits/10")

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
