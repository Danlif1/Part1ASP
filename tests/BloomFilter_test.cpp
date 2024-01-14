//
// Created by Daniel Lifshitz on 10/01/2024.
//

#include <gtest/gtest.h>
#include "BloomFilter.cpp" // here we include the code to be tested
#include "BloomFilter.h"

TEST(SumTest, BasicTest) {
BloomFilter filter = BloomFilter(256,1,2);
filter.add_url("www.example.com");
// Check if added url appears on  explicit urls blacklist.
EXPECT_EQ(filter.get_url_blacklist()[0], "www.example.com");
    filter.add_url("www.example.com0");
    filter.add_url("www.example.com1");
    filter.add_url("www.gmail.com");
    cout<<"Expected true, and got: ";
filter.check_if_blacklisted("www.example.com");
cout<<"Expected false, and got: ";
filter.check_if_blacklisted("www.gmail1.com");
cout<<endl;
}