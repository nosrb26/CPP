cmake_minimum_required(VERSION 3.0)

# set the project name
project(cartesian_vector_param)

# add the lib
#add_library(mysource SHARED vector.hh)

# add another
#add_library(mysource_2 SHARED sources_2.cpp)

# add the executable
add_executable(main main.cc vector.cc)

#target_link_libraries(main mysource)

# Compilation optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
