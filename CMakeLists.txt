cmake_minimum_required (VERSION 2.6)
project (is_tty) 

file(GLOB is_tty_sources ./src/**.c)
SET(is_tty ${is_tty_sources})

ADD_LIBRARY (is_tty  ${is_tty})
TARGET_LINK_LIBRARIES (is_tty)