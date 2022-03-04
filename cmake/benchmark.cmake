hpcc_populate_dep(benchmark)

file(GLOB TIANYICOMMON_BENCHMARK_SRC src/tianyi/common/*_benchmark.cc)
add_executable(tianyicommon_benchmark ${TIANYICOMMON_BENCHMARK_SRC})
target_include_directories(tianyicommon_benchmark PRIVATE ${benchmark_SOURCE_DIR}/include)
target_link_libraries(tianyicommon_benchmark PRIVATE tianyicommon_static benchmark_main)
