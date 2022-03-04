// tianyi accelerator framework

#include "tianyi/common/half.h"
#include <benchmark/benchmark.h>
#include <string.h>
#include <iostream>

static void BM_fp32tofp16(benchmark::State& state) {
    float* f32 = new float[state.range(0)];
    tianyi::common::float16_t* f16 = new tianyi::common::float16_t[state.range(0)];
    memset(f32, 0, 4 * state.range(0));
    memset(f16, 0, 2 * state.range(0));
    for (auto _ : state) {
        tianyi::common::ConvertFp32ToFp16(f32, f16, state.range(0));
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.items_processed() * sizeof(float));
    delete[] f16;
    delete[] f32;
}

static void BM_fp16tofp32(benchmark::State& state) {
    float* f32 = new float[state.range(0)];
    tianyi::common::float16_t* f16 = new tianyi::common::float16_t[state.range(0)];
    memset(f32, 0, 4 * state.range(0));
    memset(f16, 0, 2 * state.range(0));
    for (auto _ : state) {
        tianyi::common::ConvertFp16ToFp32(f16, f32, state.range(0));
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.items_processed() * sizeof(tianyi::common::float16_t));
    delete[] f16;
    delete[] f32;
}

BENCHMARK(BM_fp32tofp16)->Arg(1)->Arg(2)->Arg(3)->Arg(4)->Arg(5)->RangeMultiplier(2)->Range(1 << 6, 1 << 12);
BENCHMARK(BM_fp16tofp32)->Arg(1)->Arg(2)->Arg(3)->Arg(4)->Arg(5)->RangeMultiplier(2)->Range(1 << 6, 1 << 12);

static void BM_fp32tofp16_single_soft(benchmark::State& state) {
    float* f32 = new float[state.range(0)];
    tianyi::common::float16_t* f16 = new tianyi::common::float16_t[state.range(0)];
    memset(f32, 0, 4 * state.range(0));
    memset(f16, 0, 2 * state.range(0));

    for (auto _ : state) {
        for (int i = 0; i < state.range(0); ++i) {
            f16[i] = tianyi::common::float16_t::FromRawU16(tianyi::common::float2half_soft(f32[i]));
        }
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.items_processed() * sizeof(float));

    delete[] f16;
    delete[] f32;
}

static void BM_fp16tofp32_single_soft(benchmark::State& state) {
    float* f32 = new float[state.range(0)];
    tianyi::common::float16_t* f16 = new tianyi::common::float16_t[state.range(0)];
    memset(f32, 0, 4 * state.range(0));
    memset(f16, 0, 2 * state.range(0));

    for (auto _ : state) {
        for (int i = 0; i < state.range(0); ++i) {
            f32[i] = tianyi::common::half2float_soft(f16[i].Raw16());
        }
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.items_processed() * 2);

    delete[] f16;
    delete[] f32;
}

BENCHMARK(BM_fp32tofp16_single_soft)->Arg(1);
BENCHMARK(BM_fp16tofp32_single_soft)->Arg(1);

static void BM_fp32tofp16_single(benchmark::State& state) {
    float* f32 = new float[state.range(0)];
    tianyi::common::float16_t* f16 = new tianyi::common::float16_t[state.range(0)];
    memset(f32, 0, 4 * state.range(0));
    memset(f16, 0, 2 * state.range(0));

    for (auto _ : state) {
        for (int i = 0; i < state.range(0); ++i) {
            f16[i] = tianyi::common::float16_t::FromRawU16(tianyi::common::float2half(f32[i]));
        }
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.items_processed() * sizeof(float));

    delete[] f16;
    delete[] f32;
}

static void BM_fp16tofp32_single(benchmark::State& state) {
    float* f32 = new float[state.range(0)];
    tianyi::common::float16_t* f16 = new tianyi::common::float16_t[state.range(0)];
    memset(f32, 0, 4 * state.range(0));
    memset(f16, 0, 2 * state.range(0));

    for (auto _ : state) {
        for (int i = 0; i < state.range(0); ++i) {
            f32[i] = tianyi::common::half2float(f16[i].Raw16());
        }
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.items_processed() * 2);

    delete[] f16;
    delete[] f32;
}

BENCHMARK(BM_fp32tofp16_single)->Arg(1);
BENCHMARK(BM_fp16tofp32_single)->Arg(1);
