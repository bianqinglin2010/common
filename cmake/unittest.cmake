hpcc_populate_dep(googletest)

file(GLOB TIANYICOMMON_UNITTEST_SRC src/tianyi/common/*_unittest.cc)
add_executable(tianyicommon_unittest ${TIANYICOMMON_UNITTEST_SRC})

target_link_libraries(tianyicommon_unittest PRIVATE tianyicommon_static gtest gtest_main)
target_include_directories(tianyicommon_unittest PRIVATE ${googletest_SOURCE_DIR}/include)
