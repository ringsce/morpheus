set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.36.0 REQUIRED COMPONENTS
             date_time filesystem iostreams)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  #add_executable(foo foo.cc)
  target_link_libraries(foo Boost::date_time Boost::filesystem
                          Boost::iostreams)

endif()