// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_X86_SYSINFO_H_
#define _HPC_TIANYI_COMMON_X86_SYSINFO_H_

namespace tianyi { namespace common {

enum {
    ISA_X86_SSE = 0x1,
    ISA_X86_SSE2 = 0x2,
    ISA_X86_SSE3 = 0x4,
    ISA_X86_SSSE3 = 0x8,
    ISA_X86_SSE41 = 0x10,
    ISA_X86_SSE42 = 0x20,
    ISA_X86_AVX = 0x40,
    ISA_X86_AVX2 = 0x80,
    ISA_X86_FMA = 0x100,
    ISA_X86_F16C = 0x200,
    ISA_X86_AVX512 = 0x1000,
    ISA_X86_AVX512VNNI = 0x8000,
};

}}

#endif
