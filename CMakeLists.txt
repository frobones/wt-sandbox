cmake_minimum_required(VERSION 3.1)

project(WT-TUTORIAL)

include_directories(
    /usr/local/include
)

add_executable(wt-tutorial
        src/database/dbo.cpp
        src/frontend/gui.cpp
        src/database/dbo.hpp
        src/main.cpp src/frontend/gui.hpp)

target_link_libraries(wt-tutorial
    wt
    wthttp
    wtdbo
    wtdbosqlite3
)