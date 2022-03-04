// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_RETCODE_H_
#define _HPC_TIANYI_COMMON_RETCODE_H_

#include <stdint.h>

namespace tianyi { namespace common {

typedef uint32_t RetCode;

enum {
    RC_SUCCESS = 0,
    RC_OTHER_ERROR,
    RC_UNSUPPORTED,
    RC_OUT_OF_MEMORY,
    RC_INVALID_VALUE,
    RC_EXISTS,
    RC_NOT_FOUND,
    RC_PERMISSION_DENIED,
    RC_HOST_MEMORY_ERROR,
    RC_DEVICE_MEMORY_ERROR,
    RC_DEVICE_RUNTIME_ERROR,
    RC_OUT_OF_RANGE,
};

static inline const char* GetRetCodeStr(RetCode rc) {
    static const char* code_str[] = {
        "success",       "other error", "unsupported", "out of memory",
        "invalid value", "exists",      "not found",   "perimission denied",
        "host memory error", "device memory error", "device runtime error",
        "out of range",
    };
    return code_str[rc];
}

}} // namespace tianyi::common

#endif
