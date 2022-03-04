// tianyi accelerator framework

#include "tianyi/common/file_mapping.h"
#include "gtest/gtest.h"
using namespace tianyi::common;

TEST(FileMappingTest, init) {
    FileMapping fm;
    EXPECT_EQ(RC_SUCCESS, fm.Init(__FILE__));
    EXPECT_NE(RC_SUCCESS, fm.Init("a"));
}

TEST(FileMappingTest, data_and_size) {
    FileMapping fm;
    EXPECT_EQ(RC_SUCCESS, fm.Init(__FILE__));
    EXPECT_TRUE(fm.Size() > 0);
    EXPECT_NE(nullptr, fm.Data());
}
