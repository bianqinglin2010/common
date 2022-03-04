// tianyi accelerator framework

#ifndef __HPC_TIANYI_ARM_FP16FP32_H_
#define __HPC_TIANYI_ARM_FP16FP32_H_
#ifdef __cplusplus
extern "C" {
#endif //! cplusplus

void CvtFp32ToFp16(int counts, void const *src, void *dst);
void CvtFp16ToFp32(int counts, void const *src, void *dst);

#ifdef __cplusplus
}
#endif //! cplusplus
#endif //! __HPC_TIANYI_ARM_FP16FP32_H_
