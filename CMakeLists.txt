cmake_minimum_required(VERSION 3.14)

project(so5_wont_compile_tests LANGUAGES CXX)

option(SOBJECTIZER_BUILD_STATIC "Build static SObjectizer library [default: ON]" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(NOT CMAKE_CXX_STANDARD)
	message(STATUS "C++17 will be used by default")
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	set(CXX_EXTENSIONS NO)
else()
	message(STATUS "C++ standard is set to C++${CMAKE_CXX_STANDARD}")
endif()

add_subdirectory(so_5)
add_subdirectory(tests)
