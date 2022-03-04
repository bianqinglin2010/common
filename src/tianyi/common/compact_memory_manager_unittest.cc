// tianyi accelerator framework

#include "tianyi/common/compact_memory_manager.h"
#include "tianyi/common/generic_cpu_allocator.h"
#include "gtest/gtest.h"
using namespace tianyi::common;

TEST(CompactMemoryManagerTest, alloc_and_free_1) {
    const uint32_t block_bytes = 1024;
    GenericCpuAllocator ar;
    CompactMemoryManager mgr(&ar, block_bytes);

    uint32_t alloc_size = 100;
    auto ret = mgr.Alloc(alloc_size);
    EXPECT_NE(nullptr, ret);
    mgr.Free(ret, alloc_size);
    EXPECT_EQ(block_bytes, mgr.GetAllocatedBytes());

    alloc_size = block_bytes + 1;
    ret = mgr.Alloc(alloc_size);
    EXPECT_NE(nullptr, ret);
    mgr.Free(ret, alloc_size);
    EXPECT_EQ(block_bytes * 3, mgr.GetAllocatedBytes());
}

TEST(CompactMemoryManagerTest, alloc_and_free_2) {
    const uint32_t block_bytes = 1048576;
    GenericCpuAllocator ar;
    CompactMemoryManager mgr(&ar, block_bytes);

    uint32_t alloc_size = block_bytes - 1;
    auto ret = mgr.Alloc(alloc_size);
    EXPECT_NE(nullptr, ret);
    EXPECT_EQ(block_bytes, mgr.GetAllocatedBytes());
    mgr.Free(ret, alloc_size);

    // reuse last freed memories
    alloc_size = block_bytes - 2;
    ret = mgr.Alloc(alloc_size);
    EXPECT_NE(nullptr, ret);
    EXPECT_EQ(block_bytes, mgr.GetAllocatedBytes());
    // without mgr.Free()

    ret = mgr.Alloc(alloc_size);
    EXPECT_NE(nullptr, ret);
    EXPECT_EQ(block_bytes * 2, mgr.GetAllocatedBytes());
}

TEST(CompactMemoryManagerTest, reset) {
    const uint32_t block_bytes = 1048576;
    GenericCpuAllocator ar;
    CompactMemoryManager mgr(&ar, block_bytes);

    uint32_t alloc_size = block_bytes;
    auto ret1 = mgr.Alloc(alloc_size);
    EXPECT_NE(nullptr, ret1);
    EXPECT_EQ(block_bytes, mgr.GetAllocatedBytes());

    alloc_size = block_bytes * 2;
    auto ret2 = mgr.Alloc(alloc_size);
    EXPECT_NE(nullptr, ret2);
    EXPECT_EQ(block_bytes * 3, mgr.GetAllocatedBytes());

    mgr.Free(ret1, alloc_size);
    mgr.Free(ret2, alloc_size);

    EXPECT_EQ(RC_SUCCESS, mgr.Reset(block_bytes * 3));
    alloc_size = block_bytes * 3;
    auto ret = mgr.Alloc(alloc_size);
    EXPECT_NE(nullptr, ret);
    EXPECT_EQ(block_bytes * 3, mgr.GetAllocatedBytes());
    mgr.Free(ret, alloc_size);
}
