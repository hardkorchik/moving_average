cmake_minimum_required(VERSION 2.8)	

project(moving_average)	


set(SOURCE_EXE test/TestMovingAverageFilter.cpp)	

set(SOURCE_LIB src/MovingAverageFilter.cpp)	

set(HEADER src/header/MovingAverageFilter.h)

set(HEADER src/MovingAverageFilter.h)

add_library(MovingAverageFilter STATIC ${SOURCE_LIB})	

add_executable(main ${SOURCE_EXE})	

target_link_libraries(main MovingAverageFilter)		