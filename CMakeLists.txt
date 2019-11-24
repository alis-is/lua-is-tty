cmake_minimum_required (VERSION 2.6)
project (lis_tty) 

file(GLOB lis_tty_sources ./src/**.c)
SET(lis_tty ${lis_tty_sources})

ADD_LIBRARY (lis_tty  ${lis_tty})
TARGET_LINK_LIBRARIES (lis_tty)