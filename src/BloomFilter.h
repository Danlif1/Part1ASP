//
// Created by Daniel Lifshitz on 11/01/2024.
//

#ifndef PART1ASP_BLOOMFILTER_H
#define PART1ASP_BLOOMFILTER_H

#include "HashFunction.h"
#include <iostream>
#include <vector>
#include "HashOnce.h"
#include "HashTwice.h"
#include <stdexcept>

using namespace std;

class BloomFilter {
    private:
        // The array bloom filter uses.
        vector<bool>filter;
        // The size of the array of the bloom filter.
        long bloom_filter_size;
        // The array of the blacklisted urls, in case the bloom filter gives a false positive.
        vector<string> url_blacklist;
        // Array of functions used for filtering urls to blacklist.
        vector<HashFunction*> hash_functions;
    public:
        // Default constructor.
        BloomFilter();
        // Non default contractor, gets the size of the bloom filter and
        BloomFilter(int size_of_filter,int func1, int func2);
        void add_url(string added_url);
        // Getting the blacklisted urls in a vector format.
        vector<string> get_url_blacklist();
        // Checking if a url is blacklisted.
        string check_if_blacklisted(string checked_url);
        // Destructor.
        ~BloomFilter();
};
#endif //PART1ASP_BLOOMFILTER_H