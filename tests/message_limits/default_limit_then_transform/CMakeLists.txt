set(TEST_APP message_limits.default_limit_then_transform)
add_executable(${TEST_APP} main.cpp)
target_link_libraries(${TEST_APP} sobjectizer::StaticLib)

