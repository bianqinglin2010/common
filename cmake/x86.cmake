list(APPEND TIANYICOMMON_DEFINITIONS TIANYICOMMON_USE_X86)

file(GLOB_RECURSE TIANYICOMMON_X86_SRC src/tianyi/common/x86/*.cc)

if(NOT MSVC)
    list(APPEND TIANYICOMMON_X86_SRC src/tianyi/common/x86/cpuid_x86_64.S)
endif()

set_property(SOURCE src/tianyi/common/half.cc PROPERTY COMPILE_FLAGS "-mf16c")
set_property(SOURCE src/tianyi/common/x86/sysinfo.cc APPEND PROPERTY COMPILE_FLAGS "${FMA_ENABLED_FLAGS}")

list(APPEND TIANYICOMMON_SRC ${TIANYICOMMON_X86_SRC})

add_executable(cpuinfo tools/x86/cpuinfo.cc)

target_link_libraries(cpuinfo PRIVATE tianyicommon_static)

# ----- installation ----- #

file(GLOB TIANYICOMMON_X86_HEADERS
    src/tianyi/common/x86/*.h)
install(FILES ${TIANYICOMMON_X86_HEADERS}
    DESTINATION include/tianyi/common/x86)
