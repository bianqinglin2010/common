// tianyi accelerator framework

#include "tianyi/common/stripfilename.h"
#include <gtest/gtest.h>

TEST(StripFileName, all) {
    EXPECT_STREQ(tianyi::common::stripfilename("abc.cc"), "abc.cc");
    EXPECT_STREQ(tianyi::common::stripfilename("./abc.cc"), "abc.cc");
    EXPECT_STREQ(tianyi::common::stripfilename("./xxx/abc.cc"), "abc.cc");
    EXPECT_STREQ(tianyi::common::stripfilename("/xxx/abc.cc"), "abc.cc");
}
