project(libmodemctl)
add_library(libmodemctl SHARED Modem.cpp)
#pybind11_add_module(modemctlpy py_bindings.h)
target_link_libraries(libmodemctl
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )

add_subdirectory(tests)