cmake_minimum_required(VERSION 2.4)
project(hello_world)
include_directories(${PROJECT_SOURCE_DIR})
add_library(my_shared_lib SHARED foo.cpp) # Builds an shared library
#add_library(my_shared_lib foo.cpp)
add_executable(app main.cpp)
#target_link_libraries(app my_shared_lib)