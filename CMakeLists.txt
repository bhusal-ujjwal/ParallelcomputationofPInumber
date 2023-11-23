cmake_minimum_required(VERSION 3.5)

project(ParallelcomputationofPInumber LANGUAGES CXX)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ParallelcomputationofPInumber main.cpp)
install(TARGETS ParallelcomputationofPInumber
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if (OpenMP_CXX_FOUND)
    target_link_libraries(ParallelcomputationofPInumber PUBLIC OpenMP::OpenMP_CXX)
endif()


