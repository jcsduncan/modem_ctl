cmake_minimum_required(VERSION 3.12)
project(modemctl)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS system filesystem REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(PYBIND11_PYTHON_VERSION 3.6)
set(PYBIND11_CPP_STANDARD -std=c++11)

message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
add_subdirectory(libmodemctl)
add_subdirectory(py_bindings)