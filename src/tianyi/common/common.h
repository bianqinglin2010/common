// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_COMMON_H_
#define _HPC_TIANYI_COMMON_COMMON_H_

#ifdef _MSC_VER
#define TIANYICOMMON_PUBLIC __declspec(dllexport)
#else
#define TIANYICOMMON_PUBLIC __attribute__((visibility("default")))
#endif

#endif
