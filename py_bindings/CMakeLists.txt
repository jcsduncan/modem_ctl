
add_subdirectory(pybind11)
include_directories(${modemctl_SOURCE_DIR}/libmodemctl)
pybind11_add_module(Modem py_bindings.cpp ../libmodemctl/Modem.cpp ../libmodemctl/Serial.cpp ../libmodemctl/Serial.h ../libmodemctl/Modem.cpp ../libmodemctl/Modem.h ${PROJECT_SOURCE_DIR}/at_commands.h ../libmodemctl/utils.cpp ../libmodemctl/utils.h)

#target_include_directories(Modem PUBLIC ${modemctl_SOURCE_DIRS})

target_link_libraries(Modem PUBLIC
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${PYTHON_LIBRARIES}
        )

enable_testing()
add_test(NAME pybind_test
        COMMAND python3 ${CMAKE_SOURCE_DIR}/tests/test.py)

set_tests_properties (pybind_test PROPERTIES ENVIRONMENT
        "PYTHONPATH=${PROJECT_BINARY_DIR}")