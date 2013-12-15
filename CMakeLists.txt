cmake_minimum_required(VERSION 2.6)

enable_testing()

project(bloomfilter)

add_definitions(
    -g -O2 -Wall -W
    )

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(tools)
