cmake_minimum_required(VERSION 3.1)

project(WT-TUTORIAL)

include_directories(
    /usr/local/include
)

add_executable(wt-tutorial
        dbo.cpp
        gui.cpp
)

target_link_libraries(wt-tutorial
    wt
    wthttp
    wtdbo
    wtdbosqlite3
)