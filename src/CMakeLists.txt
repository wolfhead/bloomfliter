include_directories(
    "../include"
    )

add_library(bloomfilter
    "hasher/details/MurmurHash3.cpp")
