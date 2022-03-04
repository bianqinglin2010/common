// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_HIP_HIP_TYPES_H_
#define _HPC_TIANYI_COMMON_HIP_HIP_TYPES_H_

#include <stdint.h>

namespace tianyi { namespace common { namespace hip {

static inline uint32_t GetDataFormatChannelAlignment(dataformat_t dt) {
    static const uint32_t data_format_alignment[] = {
        0,  // UNKNOWN
        1,  // NDARRAY
        8,  // NHWC8
        16, // NHWC16
        2,  // N2CX
        4,  // N4CX
        8,  // N8CX
        16, // N16CX
        32, // N32CX
    };
    return data_format_alignment[dt];
}

}}} // namespace tianyi::common::cuda

#endif
