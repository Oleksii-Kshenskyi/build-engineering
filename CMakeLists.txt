cmake_minimum_required(VERSION 3.26.0)

project(sorting)
set(LIB_DIR lib)
set(LIB_SRC ${LIB_DIR}/sort.cpp)
include_directories(${LIB_DIR})

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)
pybind11_add_module(${PROJECT_NAME} ${LIB_SRC})
install(TARGETS ${PROJECT_NAME} DESTINATION .)