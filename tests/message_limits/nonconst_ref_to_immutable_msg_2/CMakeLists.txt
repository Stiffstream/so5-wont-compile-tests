set(TEST_APP message_limits.nonconst_ref_to_immutable_msg_2)
add_executable(${TEST_APP} main.cpp)
target_link_libraries(${TEST_APP} sobjectizer::StaticLib)

