// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_LOCK_UTILS_H_
#define _HPC_TIANYI_COMMON_LOCK_UTILS_H_

namespace tianyi { namespace common {

class DummyLock final {
public:
    void ReadLock() {}
    void WriteLock() {}
    void Unlock() {}
};

template <typename T>
class ReadLockGuard final {
public:
    ReadLockGuard(T* lock) : lock_(lock) {
        lock->ReadLock();
    }
    ~ReadLockGuard() {
        lock_->Unlock();
    }

private:
    T* lock_;
};

template <typename T>
class WriteLockGuard final {
public:
    WriteLockGuard(T* lock) : lock_(lock) {
        lock->WriteLock();
    }
    ~WriteLockGuard() {
        lock_->Unlock();
    }

private:
    T* lock_;
};

}} // namespace tianyi::common

#endif
