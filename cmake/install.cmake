
file(GLOB TIANYICOMMON_HEADERS
    src/tianyi/common/*.h)
install(FILES ${TIANYICOMMON_HEADERS}
    DESTINATION include/tianyi/common)

file(GLOB TIANYICOMMON_PARAM_HEADERS
    src/tianyi/common/params/*.h)
install(FILES ${TIANYICOMMON_PARAM_HEADERS}
    DESTINATION include/tianyi/common/params)

install(TARGETS tianyicommon_static DESTINATION lib)

set(TIANYICOMMON_CMAKE_CONFIG_FILE ${CMAKE_CURRENT_BINARY_DIR}/generated/tianyicommon-config.cmake)
configure_file(cmake/tianyicommon-config.cmake.in
    ${TIANYICOMMON_CMAKE_CONFIG_FILE}
    @ONLY)
install(FILES ${TIANYICOMMON_CMAKE_CONFIG_FILE} DESTINATION lib/cmake/tianyi)
unset(TIANYICOMMON_CMAKE_CONFIG_FILE)
