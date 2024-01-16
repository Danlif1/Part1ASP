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
        vector<bool> filter;
        // The size of the array of the bloom filter.
        unsigned long bloomFilterSize;
        // The array of the blacklisted urls, in case the bloom filter gives a false positive.
        vector<string> urlBlacklist = std::vector<string>();
        // Array of functions used for filtering urls to blacklist.
        vector<HashFunction*> hashFunctions;
    public:
        // Default constructor.
        BloomFilter();
        // Non default contractor, gets the size of the bloom filter and
        BloomFilter(unsigned long sizeOfFilter, const vector<int>& Hashes);
        // Adding the url to the blacklist.
        void addUrl(string addedUrl);
        // Getting the blacklisted urls in a vector format.
        vector<string> getUrlBlacklist();
        // Checking if a url is blacklisted.
        string checkIfBlacklisted(string checkedUrl);
        // Destructor.
        ~BloomFilter();
};
#endif //PART1ASP_BLOOMFILTER_H