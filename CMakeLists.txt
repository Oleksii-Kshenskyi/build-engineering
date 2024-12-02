cmake_minimum_required(VERSION 3.26.0)

project(sorting)

find_package(pybind11 REQUIRED)
find_package(GTest CONFIG REQUIRED)

set(LIB_DIR lib)
set(TEST_DIR test)
set(LIB_SRC ${LIB_DIR}/core.cpp)
set(PY_SRC ${LIB_DIR}/py.cpp)
include_directories(${LIB_DIR})

enable_testing()

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}_core STATIC ${LIB_SRC})
set_target_properties(${PROJECT_NAME}_core PROPERTIES POSITION_INDEPENDENT_CODE ON)

set(PYBIND11_FINDPYTHON ON)
pybind11_add_module(${PROJECT_NAME} ${PY_SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_core)
install(TARGETS ${PROJECT_NAME} DESTINATION .)

add_executable(test_${PROJECT_NAME} ${TEST_DIR}/test_${PROJECT_NAME}.cpp)
target_link_libraries(test_${PROJECT_NAME} PRIVATE GTest::gtest_main ${PROJECT_NAME}_core)

include(GoogleTest)
gtest_discover_tests(test_${PROJECT_NAME})