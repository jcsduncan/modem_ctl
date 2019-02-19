include_directories(${libmodemctl_SOURCE_DIR})
enable_testing()
add_executable(test_modem test_modem.cpp)

target_link_libraries(test_modem libmodemctl)

add_test(test_modem test_modem)

add_custom_command(
        OUTPUT testing
        COMMAND ctest --output-on-failure
)

add_custom_target(
        test_force ALL
        DEPENDS testing test_modem
)