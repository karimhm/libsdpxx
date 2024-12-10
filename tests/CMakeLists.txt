cmake_minimum_required(VERSION 3.10)

include(FetchContent)
include(GoogleTest)

# Fetch GoogleTest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SRC
     "*.cc"
)

enable_testing()
# Define the test executable
add_executable(libsdpxx_tests ${TEST_SRC})

set_target_properties(libsdpxx_tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_VISIBILITY_PRESET hidden
)

# Link the test executable with GoogleTest and your library
target_link_libraries(libsdpxx_tests PRIVATE
    GTest::gtest
    GTest::gtest_main
    libsdpxx
)

#gtest_discover_tests(libsdpxx_tests)
add_test(NAME libsdpxx_tests COMMAND libsdpxx_tests)
