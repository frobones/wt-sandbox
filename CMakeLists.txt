cmake_minimum_required(VERSION 3.1)

project(WT-TUTORIAL)

include_directories(
    /usr/local/include
)

add_executable(wt-tutorial
    src/database/dbo.cpp
    src/database/dbo.hpp
    src/database/unit.hpp
    src/database/unit_enum.hpp
    src/database/unit.cpp
    src/frontend/helper.cpp
    src/frontend/helper.hpp
    src/frontend/gui.hpp
    src/frontend/gui.cpp
    src/main.cpp
)

target_include_directories(wt-tutorial PUBLIC src)

target_link_libraries(wt-tutorial
    wt
    wthttp
    wtdbo
    wtdbosqlite3
)

target_compile_options(wt-tutorial PUBLIC
    -Werror
)