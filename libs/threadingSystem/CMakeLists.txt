cmake_minimum_required(VERSION 3.21.1)
project(RingsCEThreads LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/corelib/threads/semaphores")

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_executable(threads
    semaphores.cpp
    wait.cpp
)

target_link_libraries(threads PUBLIC
    Qt::Core
)

install(TARGETS threads
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
