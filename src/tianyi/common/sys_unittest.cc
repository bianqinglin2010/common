// tianyi accelerator framework

#include "tianyi/common/sys.h"
#include <gtest/gtest.h>
#include <stdio.h>

#ifdef TIANYICOMMON_USE_X86
TEST(tianyicommon, x86SysInfo) {
    using namespace tianyi::common;
    fprintf(stdout, "[x86SysInfo] 0x%u\n", GetCpuInfo()->isa);
}
#endif //! TIANYICOMMON_USE_X86

#define IS_ALIGNED(p, alignment) ((uintptr_t)p % (uintptr_t)alignment == 0)

TEST(tianyicommon, AlignedAlloc) {
    void* p0 = tianyi::common::AlignedAlloc(100, 64);
    EXPECT_TRUE(IS_ALIGNED(p0, 64));
    char* cp = (char*)p0;
    for (int i = 0; i < 100; ++i) {
        cp[i] = i;
    }
    tianyi::common::AlignedFree(p0);
}
