//
// Created by Daniel Lifshitz on 10/01/2024.
//

#include <gtest/gtest.h>
#include "../src/BloomFilter.h" // here we include the code to be tested

// Checking for true positive
TEST(TruePositive, BasicTest) {
    BloomFilter filter = BloomFilter(256, {1, 2});
    cout << "adding one" << endl;
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com"), "true true");
}


// Checking for false positive.
TEST(FalsePositive, BasicTest) {
    BloomFilter filter(1,{1,2});
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com1"), "true false");
}

// Checking for true negative.
TEST(TrueNegative, BasicTest) {
      BloomFilter filter = BloomFilter(256,{1,2});
      filter.add_url("www.example.com");
//    // Check if added url appears on explicit urls blacklist.
      EXPECT_EQ(filter.check_if_blacklisted("www.example.com1"), "false");
}

// Checking for a lot of hash functions.
TEST(TruePositive, HashesTest) {
    BloomFilter filter = BloomFilter(256,{1,2,1,2,1,1,1,2});
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com1"), "false");
}
TEST(FalsePositive, HashesTest) {
    BloomFilter filter = BloomFilter(5,{1,2,1,2,1,1,1,2});
    filter.add_url("www.example.com");
    filter.add_url("www.example.com2");
    filter.add_url("www.example.com3");
    filter.add_url("www.example.com4");
    filter.add_url("www.example.com5");
    filter.add_url("www.example.com6");


    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com1"), "true false");
}

// Checking for true negative.
TEST(TrueNegative, HashesTest) {
    BloomFilter filter = BloomFilter(256,{1,2,1,2,1,1,1,2});
    filter.add_url("www.example.com");
//    // Check if added url appears on explicit urls blacklist.
    EXPECT_EQ(filter.check_if_blacklisted("www.example.com1"), "false");
}

// We can't check for a true negative with a lot of blacklisted urls in a static mode.