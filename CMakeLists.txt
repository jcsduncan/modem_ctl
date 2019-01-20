cmake_minimum_required(VERSION 3.12)
project(modemctl)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS system filesystem REQUIRED)

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()

message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

add_executable(modemctl main.cpp Serial.cpp Serial.h Modem.cpp Modem.h at_commands.h utils.cpp utils.h)

target_link_libraries(modemctl
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )