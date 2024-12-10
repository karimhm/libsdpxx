cmake_minimum_required(VERSION 3.10)

project(libsdpxx VERSION 1.0.0 LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Create the interface library
add_library(libsdpxx INTERFACE)

target_include_directories(libsdpxx INTERFACE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(libsdpxx PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

install(DIRECTORY include/ DESTINATION include)

add_subdirectory(tests)
enable_testing()

export(TARGETS libsdpxx FILE libsdpxxConfig.cmake)
