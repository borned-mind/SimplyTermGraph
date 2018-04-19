cmake_minimum_required(VERSION 2.8)
project(libSimplyTermGraph)


include_directories(src)
add_subdirectory(src)
add_executable(test test.cpp)
target_link_libraries(test stg)
#file(COPY ... DESTINATION ...)

