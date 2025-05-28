set(TEST_APP mutable_msg.mutable_signal_send)
add_executable(${TEST_APP} main.cpp)
target_link_libraries(${TEST_APP} sobjectizer::StaticLib)

