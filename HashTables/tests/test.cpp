#include "/Users/blakedickerson/Desktop/AnishasLearnings/HashTables/src/functions.cpp"

#include "gtest/gtest.h"

TEST(FunctionTest, adding) {
    EXPECT_EQ(add(1, 2), 3);
}

TEST(FunctionTest, subtraction) {
    EXPECT_EQ(sub(1, 2), -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}