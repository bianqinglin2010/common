// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_ALLOCATOR_H_
#define _HPC_TIANYI_COMMON_ALLOCATOR_H_

#include <stdint.h>

namespace tianyi { namespace common {

class Allocator {
public:
    virtual ~Allocator() {}
    virtual void* Alloc(uint64_t size) = 0;
    virtual void Free(void* ptr) = 0;
};

}} // namespace tianyi::common

#endif
