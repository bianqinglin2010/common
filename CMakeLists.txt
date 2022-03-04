cmake_minimum_required(VERSION 3.14)
project(tianyi.common)

include(cmake/deps.cmake)

# --------------------------------------------------------------------------- #

option(TIANYICOMMON_BUILD_TESTS "build tests" ON)
option(TIANYICOMMON_BUILD_BENCHMARK "build benchmark" ON)
option(TIANYICOMMON_INSTALL "install tianyi.common headers and libs" ON)
option(TIANYICOMMON_ENABLE_PYTHON_API "enable python api support" OFF)

option(TIANYICOMMON_ENABLE_LUA_API "enable lua api support" OFF)
option(TIANYICOMMON_HOLD_DEPS "don't update dependencies" OFF)

# --------------------------------------------------------------------------- #

if(TIANYICOMMON_ENABLE_PYTHON_API)
    add_subdirectory(python)
endif()

if(TIANYICOMMON_ENABLE_LUA_API)
    add_subdirectory(lua)
endif()

file(GLOB TIANYICOMMON_SRC
    src/tianyi/common/*.cc)

set(TIANYICOMMON_INCLUDES)
list(APPEND TIANYICOMMON_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(TIANYICOMMON_LINK_LIBRARIES)
set(TIANYICOMMON_DEFINITIONS)

if(HPCC_USE_X86_64)
    include(cmake/x86.cmake)
endif()

if(HPCC_USE_AARCH64)
    include(cmake/arm.cmake)
endif()

list(FILTER TIANYICOMMON_SRC EXCLUDE REGEX "(.*)_unittest\\.cc$")
list(FILTER TIANYICOMMON_SRC EXCLUDE REGEX "(.*)_benchmark\\.cc$")

# --------------------------------------------------------------------------- #

add_library(tianyicommon_static STATIC ${TIANYICOMMON_SRC})
target_link_libraries(tianyicommon_static PUBLIC ${TIANYICOMMON_LINK_LIBRARIES})
target_include_directories(tianyicommon_static PUBLIC ${TIANYICOMMON_INCLUDES})
target_compile_definitions(tianyicommon_static PUBLIC ${TIANYICOMMON_DEFINITIONS})
target_compile_features(tianyicommon_static PUBLIC cxx_std_11)

if(TIANYICOMMON_INSTALL)
    include(cmake/install.cmake)
endif()

if(TIANYICOMMON_BUILD_TESTS)
    include(cmake/unittest.cmake)
endif()

if(TIANYICOMMON_BUILD_BENCHMARK)
    include(cmake/benchmark.cmake)
endif()
