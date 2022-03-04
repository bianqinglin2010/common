// tianyi accelerator framework

#include "tianyi/common/sys.h"
#include "tianyi/common/log.h"
#include "tianyi/common/x86/sysinfo.h"

int main () {
    tianyi::common::CpuInfo info_id, info_run;
    tianyi::common::GetCPUInfoByCPUID(&info_id);
    tianyi::common::GetCPUInfoByRun(&info_run);

    LOG(INFO) << "Info From CPUID:";
    LOG(INFO) << "Vendor: " << info_id.vendor_id;
    LOG(INFO) << "VNNI  : " << (bool)(info_id.isa & tianyi::common::ISA_X86_AVX512VNNI);
    LOG(INFO) << "AVX512: " << (bool)(info_id.isa & tianyi::common::ISA_X86_AVX512);
    LOG(INFO) << "AVX2  : " << (bool)(info_id.isa & tianyi::common::ISA_X86_AVX2);
    LOG(INFO) << "FMA3  : " << (bool)(info_id.isa & tianyi::common::ISA_X86_FMA);
    LOG(INFO) << "AVX   : " << (bool)(info_id.isa & tianyi::common::ISA_X86_AVX);
    LOG(INFO) << "SSE   : " << (bool)(info_id.isa & tianyi::common::ISA_X86_SSE);
    LOG(INFO) << "L1 D-Cahce: " << info_id.l1_cache_size;
    LOG(INFO) << "L2 Cahce: " << info_id.l2_cache_size;
    LOG(INFO) << "L3 Cahce: " << info_id.l3_cache_size;

    LOG(INFO) << "Info From RUN:";
    LOG(INFO) << "Vendor: " << info_run.vendor_id;
    LOG(INFO) << "VNNI  : " << (bool)(info_run.isa & tianyi::common::ISA_X86_AVX512VNNI);
    LOG(INFO) << "AVX512: " << (bool)(info_run.isa & tianyi::common::ISA_X86_AVX512);
    LOG(INFO) << "AVX2  : " << (bool)(info_run.isa & tianyi::common::ISA_X86_AVX2);
    LOG(INFO) << "FMA3  : " << (bool)(info_run.isa & tianyi::common::ISA_X86_FMA);
    LOG(INFO) << "AVX   : " << (bool)(info_run.isa & tianyi::common::ISA_X86_AVX);
    LOG(INFO) << "SSE   : " << (bool)(info_run.isa & tianyi::common::ISA_X86_SSE);
    LOG(INFO) << "L1 D-Cahce: " << info_run.l1_cache_size;
    LOG(INFO) << "L2 Cahce: " << info_run.l2_cache_size;
    LOG(INFO) << "L3 Cahce: " << info_run.l3_cache_size;

    return 0;
}
