project (lis_tty) 

file(GLOB lis_tty_sources ./src/**.c)
set(lis_tty ${lis_tty_sources})

add_library(lis_tty  ${lis_tty})
target_link_libraries(lis_tty)