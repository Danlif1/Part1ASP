//
// Created by Daniel Lifshitz on 10/01/2024.
//

#include <gtest/gtest.h>
#include "../src/BloomFilter.h" // here we include the code to be tested

// Checking for true positive
TEST(TruePositive, BasicTest) {
    BloomFilter filter = BloomFilter(256,1,2);
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com"), "true true");
}


// Checking for false positive.
TEST(FalsePositive, BasicTest) {
    BloomFilter filter = BloomFilter(1,1,2);
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com1"), "true false");
}

// Checking for true negative.
TEST(TrueNegative, BasicTest) {
    BloomFilter filter = BloomFilter(256,1,2);
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com1"), "false");
}

// We can't check for a true negative with a lot of blacklisted urls in a static mode.