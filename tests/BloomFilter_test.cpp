//
// Created by Daniel Lifshitz on 10/01/2024.
//

#include <gtest/gtest.h>
#include "BloomFilter.cpp" // here we include the code to be tested
#include "BloomFilter.h"

TEST(SumTest, BasicTest) {
BloomFilter filter = BloomFilter();
EXPECT_EQ(filter.add_url("www.example.com"), true);
}