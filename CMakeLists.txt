cmake_minimum_required(VERSION 3.12)
project(modemctl)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(pybind11 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(PYBIND11_PYTHON_VERSION 3.6)
set(PYBIND11_CPP_STANDARD -std=c++11)
#find_package(PythonLibs REQUIRED)
#include_directories(${PYTHON_INCLUDE_DIRS})

message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

#add_library(modemctl SHARED main.cpp Serial.cpp Serial.h Modem.cpp Modem.h at_commands.h utils.cpp utils.h py_bindings.h)
#pybind11_add_module(modemctlpy py_bindings.h)
#target_link_libraries(modemctl
#        ${Boost_FILESYSTEM_LIBRARY}
#        ${Boost_SYSTEM_LIBRARY}
#        )
#add_executable(modemctl main.cpp Serial.cpp Serial.h Modem.cpp Modem.h at_commands.h utils.cpp utils.h py_bindings.cpp)
pybind11_add_module(Modem Modem.cpp Serial.cpp Serial.h Modem.cpp Modem.h at_commands.h utils.cpp utils.h)

target_link_libraries(Modem PUBLIC
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${PYTHON_LIBRARIES}
        )