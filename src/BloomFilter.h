//
// Created by Daniel Lifshitz on 11/01/2024.
//

#ifndef PROJECT_PART_1_CALC_H
#define PROJECT_PART_1_CALC_H
#include "HashFunction.h"
#pragma once
using namespace std;
class BloomFilter {
    private:
        vector<bool>filter;
        vector<string> url_blacklist;
        // array of functions used for filtering urls to blacklist.
         vector<HashFunction*> hash_functions;
    public:
         void add_url(string added_url);
         BloomFilter();
         BloomFilter(int size_of_filter,int func1, int func2);
         vector<string> get_url_blacklist();
         void check_if_blacklisted(string checked_url);
         long hash_url_using_all_functions(string url);
};
#endif //PROJECT_PART_1_CALC_H