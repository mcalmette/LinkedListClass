
# cmake_minimum_required(VERSION 2.6)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

# locate gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# create unit test executable
add_executable(linkedtest linked_test.cpp)
target_link_libraries(linkedtest ${GTEST_LIBRARIES} pthread)

# create performance executable
add_executable(linkedperf linked_perf.cpp)
