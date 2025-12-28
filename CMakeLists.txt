
cmake_minimum_required(VERSION 3.10)
project(ObjektinisProgramavimasV03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    studentas.cpp
)

add_executable(main ${SOURCES})