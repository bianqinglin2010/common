option(TIANYICOMMON_USE_ARMV8_2 "build tianyicommon with armv8.2-a support." OFF)

file(GLOB_RECURSE TIANYICOMMON_ARM_SRC src/tianyi/common/arm/*.cc)
list(APPEND TIANYICOMMON_ARM_SRC src/tianyi/common/arm/fp16fp32_cvt.S)

list(APPEND TIANYICOMMON_DEFINITIONS TIANYICOMMON_USE_ARM)

if (TIANYICOMMON_USE_ARMV8_2)
    set_property(SOURCE src/tianyi/common/half.cc PROPERTY COMPILE_FLAGS "-march=armv8.2-a+fp16")
    set_property(SOURCE src/tianyi/common/arm/sysinfo.cc APPEND PROPERTY COMPILE_FLAGS "-march=armv8.2-a+fp16")
    list(APPEND TIANYICOMMON_DEFINITIONS TIANYICOMMON_USE_ARMV8_2)
endif()

list(APPEND TIANYICOMMON_SRC ${TIANYICOMMON_ARM_SRC})

# ----- installation ----- #

file(GLOB TIANYICOMMON_ARM_HEADERS
    src/tianyi/common/arm/*.h)
install(FILES ${TIANYICOMMON_ARM_HEADERS}
    DESTINATION include/tianyi/common/arm)
