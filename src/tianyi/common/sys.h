// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_SYS_H_
#define _HPC_TIANYI_COMMON_SYS_H_

#include <stdint.h>

namespace tianyi { namespace common {

typedef uint32_t isa_t;
static constexpr uint32_t ISA_UNKNOWN = 0;

struct CpuInfo {
    isa_t isa;
    uint64_t l1_cache_size;
    uint64_t l2_cache_size;
    uint64_t l3_cache_size;
    char vendor_id[64];
};

const CpuInfo* GetCpuInfo(int which = 0);

static inline uint64_t GetCpuCacheL1(int which = 0) {
    return GetCpuInfo(which)->l1_cache_size;
}
static inline uint64_t GetCpuCacheL2(int which = 0) {
    return GetCpuInfo(which)->l2_cache_size;
}
static inline uint64_t GetCpuCacheL3(int which = 0) {
    return GetCpuInfo(which)->l3_cache_size;
}
static inline const char* GetCpuVendor(int which = 0) {
    return GetCpuInfo(which)->vendor_id;
}

static inline bool CpuSupports(isa_t flag, int which = 0) {
    return (GetCpuInfo(which)->isa & flag);
}

static inline isa_t GetCpuISA(int which = 0) {
    return GetCpuInfo(which)->isa;
}

void GetCPUInfoByCPUID(CpuInfo* info);
void GetCPUInfoByRun(CpuInfo* info);

void* AlignedAlloc(uint64_t size, uint32_t alignment);
void AlignedFree(void* p);

}} // namespace tianyi::common

#endif
