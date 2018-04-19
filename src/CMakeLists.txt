set(NAME_PROJECT SimplyTermGraph_lib)
cmake_minimum_required(VERSION 2.8)

project(${NAME_PROJECT})

set(SOURCE_LIB term.cpp)

if( DEFINED $ENV{LIBSHARED} )
	add_library(stg SHARED ${SOURCE_LIB})
else()
	add_library(stg STATIC ${SOURCE_LIB})
endif()


