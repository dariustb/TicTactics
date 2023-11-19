#include <gtest/gtest.h>

namespace {
    int getMeaningOfLife() { return 42; }
}

TEST(SmokeTest, SimpleAssertion) {
    ASSERT_EQ(42, getMeaningOfLife());
}