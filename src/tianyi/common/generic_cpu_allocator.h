// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_GENERIC_CPU_ALLOCATOR_H_
#define _HPC_TIANYI_COMMON_GENERIC_CPU_ALLOCATOR_H_

#include "tianyi/common/allocator.h"
#include "tianyi/common/sys.h"
#include <new>
#include <utility> // std::forward

namespace tianyi { namespace common {

class GenericCpuAllocator final : public Allocator {
public:
    GenericCpuAllocator(uint64_t alignment = 64) : alignment_(alignment) {}

    template <typename T, typename... Args>
    T* TypedAlloc(Args&&... args) {
        auto obj = (T*)Alloc(sizeof(T));
        if (obj) {
            new (obj) T(std::forward<Args>(args)...);
        }
        return obj;
    }

    template <typename T>
    void TypedFree(T* obj) {
        if (obj) {
            obj->~T();
            Free(obj);
        }
    }

    void* Alloc(uint64_t size) override {
        return tianyi::common::AlignedAlloc(size, alignment_);
    }

    void Free(void* ptr) override {
        tianyi::common::AlignedFree(ptr);
    }

private:
    uint64_t alignment_;
};

}} // namespace tianyi::common

#endif
