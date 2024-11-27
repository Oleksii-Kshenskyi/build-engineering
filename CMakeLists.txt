cmake_minimum_required(VERSION 3.24.0)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "")

project(the_sort)
set(LIB_DIR lib)
set(LIB_SRC ${LIB_DIR}/sort.cpp)
include_directories(${LIB_DIR})

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)


set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)
pybind11_add_module(${PROJECT_NAME} ${LIB_SRC})
install(TARGETS ${PROJECT_NAME} DESTINATION .)