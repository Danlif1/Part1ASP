//
// Created by Itamar Berger
//

#include "BloomFilter.h"

using namespace std;

/**
 * Bloom filter constructor.
 */
BloomFilter::BloomFilter(){
    // Getting the size of the bloom filter.
    cin >> bloom_filter_size;
    // Initial an array of bits to represent a bloom filter.
    filter = vector<bool>(bloom_filter_size);
    // Initializing the input for the type of function.
    int num_of_func;
    // Iterate while user is typing hash functions for our bloom filter.
    while (cin.get() != '\n') {
        // Getting the type of function.
        cin >> num_of_func;
        switch (num_of_func) {
            case 1:
                hash_functions.push_back(new HashOnce());
                break;
            case 2:
                hash_functions.push_back(new HashTwice());
                break;
            default:
                throw invalid_argument("invalid argument");
        }
    }
}


BloomFilter::BloomFilter(unsigned long size_of_filter,const vector<int>& Hashes){
    bloom_filter_size = size_of_filter;
    for (int func : Hashes) {
        switch (func) {
            case 1:
                hash_functions.push_back(new HashOnce);
                break;
            case 2:
                hash_functions.push_back(new HashTwice);
                break;
            default:
                throw invalid_argument("invalid argument");
        }
    }
    filter = vector<bool>(bloom_filter_size);
}

// Getting the blacklisted urls in a vector format.
vector<string> BloomFilter::get_url_blacklist(){
    return url_blacklist;
}

/**
 * Adding a url to the blacklist.
 * @param added_url The url we want to add.
 */
void  BloomFilter::add_url(string added_url) {
    // add current url to blacklist (list of explicit urls).
    url_blacklist.push_back(added_url);

    // Perform hashing to url using all functions of current filter and add them to the bloom filter.
    unsigned long hashed_url = 0;
    for (HashFunction* hash : hash_functions) {
        if (hashed_url == 0) {
            hashed_url = hash->hash_url(added_url);
        } else {
            hashed_url = hash->hash_url(to_string(hashed_url));
        }
        unsigned long hashed_index = hashed_url % bloom_filter_size;
        filter[hashed_index] = true;
    }
}

/**
 * Checking if the url is blacklisted.
 * @param checked_url The url we want to check.
 */
string BloomFilter::check_if_blacklisted(string checked_url){
    string answer = "false";
    unsigned long hashed_url = 0;
    for (HashFunction* hash : hash_functions) {
        if (hashed_url == 0) {
            hashed_url = hash->hash_url(checked_url);
        } else {
            hashed_url = hash->hash_url(to_string(hashed_url));
        }
        unsigned long hashed_index = hashed_url % bloom_filter_size;
        if(!filter[hashed_index]) {
            return answer;
        }
    }
    answer = "true ";
    // Iterate through blacklist, and search for checked url.
    for(const string& s : get_url_blacklist()) {
        if (s == checked_url) {
            answer += "true";
            return answer;
        }
    }
    answer += "false";
    return answer;
}


BloomFilter::~BloomFilter() {
    for (HashFunction* hash : hash_functions) {
        delete hash;
    }
}