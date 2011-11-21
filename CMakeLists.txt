cmake_minimum_required(VERSION 2.6.2)

project(slow)

add_executable(slowbit slowbuffer.cpp slowbit.cpp)
add_executable(slowstd slowbuffer.cpp slowstd.cpp)
