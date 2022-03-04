// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_COMPACT_MEMORY_MANAGER_H_
#define _HPC_TIANYI_COMMON_COMPACT_MEMORY_MANAGER_H_

#include "tianyi/common/allocator.h"
#include "tianyi/common/retcode.h"
#include <vector>
#include <map>
#include <set>

namespace tianyi { namespace common {

class CompactMemoryManager final {
public:
    /** @param block_bytes MUST be power of 2 */
    CompactMemoryManager(Allocator* ar, uint64_t block_bytes = 1048576);
    ~CompactMemoryManager();

    void* Alloc(uint64_t bytes);
    void Free(void* addr, uint64_t bytes);

    /**
       @brief replaces all blocks with a new single block.
       @note make sure that this manager is not used when calling Defragment().
    */
    tianyi::common::RetCode Defragment();

    /**
       @brief frees all blocks and reserve a new single block with size `bytes`.
       @note make sure that this manager is not used when calling `Reset()`.
       @param reserved_bytes if it is 0, all blocks are freed.
    */
    tianyi::common::RetCode Reset(uint64_t reserved_bytes = 0);

    uint64_t GetAllocatedBytes() const {
        return allocated_bytes_;
    }

private:
    void Clear();

private:
    const uint64_t block_bytes_;
    Allocator* allocator_;
    uint64_t allocated_bytes_;
    std::map<void*, uint64_t> addr2bytes_;
    std::map<uint64_t, std::set<void*>> bytes2addr_;
    std::vector<void*> blocks_;
};

}} // namespace tianyi::common

#endif
