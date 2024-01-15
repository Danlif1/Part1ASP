//
// Created by Daniel Lifshitz on 10/01/2024.
//

#include <gtest/gtest.h>
#include "../src/BloomFilter.h" // here we include the code to be tested

// Checking an easy true positive
TEST(TruePositive, BasicTest) {
    BloomFilter filter = BloomFilter(256,1,2);
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com"), "true true");
}

// Checking a hard true positive.
TEST(TruePositive, LongTest) {
    BloomFilter filter = BloomFilter(300,1,2);
    string str = "www.example.com";
    for (int i = 0; i < 100; i++) {
        filter.add_url("www.example.com" + to_string(i));
    }
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com50"), "true true");
}

// Checking an easy false positive.
TEST(FalsePositive, BasicTest) {
    BloomFilter filter = BloomFilter(1,1,2);
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com1"), "true false");
}

// Checking a hard false positive
TEST(FalsePositive, LongTest) {
    BloomFilter filter = BloomFilter(30,1,2);
    string str = "www.example.com";
    for (int i = 0; i < 200; i++) {
        filter.add_url("www.example.com" + to_string(i));
    }
    EXPECT_EQ(filter.check_if_blacklisted("not.www.example.com50"), "true false");
}

// Checking an easy true negative.
TEST(TrueNegative, BasicTest) {
    BloomFilter filter = BloomFilter(256,1,2);
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com1"), "false");
}

// We can't check for a true negative with a lot of blacklisted urls in a static mode.