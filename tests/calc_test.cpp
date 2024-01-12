//
// Created by Daniel Lifshitz on 10/01/2024.
//

#include <gtest/gtest.h>
#include "calc.h" // here we include the code to be tested
TEST(SumTest, BasicTest) {
EXPECT_EQ(sum(1,2), 3);
}