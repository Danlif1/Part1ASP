//
// Created by Itamar Berger
//

#include "BloomFilter.h"

using namespace std;

/**
 * Bloom filter constructor for manual run.
 */
BloomFilter::BloomFilter(){
    // Getting the size of the bloom filter and the hashes.
    string tempBloomFilter;
    vector<int> v;
    while (!bloomFilterSize) {
        getline(cin,tempBloomFilter);

        // constructing stream from the string
        stringstream ss(tempBloomFilter);

        // declaring vector to store the string after split
        v.clear();

        // using while loop until the getline condition is
        // satisfied
        // ' ' represent split the string whenever a space is
        // found in the original string
        bool first = true;
        while (getline(ss, tempBloomFilter, ' ')) {
            if (first) {
                try {
                    bloomFilterSize = stoul(tempBloomFilter);
                } catch (exception e) {
                    break;
                }
                first = false;
            }
            else {
                try {
                    // store token string in the vector
                    int func = stoi(tempBloomFilter);
                    if (func == 1 || func == 2) {
                        v.push_back(stoi(tempBloomFilter));
                    }
                } catch (exception e) {
                    continue;
                }
            }
        }
    }
    // Iterate while user is typing hash functions for our bloom filter.
    for (int func : v) {
        switch (func) {
            case 1:
                hashFunctions.push_back(new HashOnce());
                break;
            case 2:
                hashFunctions.push_back(new HashTwice());
                break;
            default:
                throw invalid_argument("invalid argument");
        }
    }
    // Initial an array of bits to represent a bloom filter.
    filter = vector<bool>(bloomFilterSize);

}

/**
 * Constructor for tests.
 * In tests we can't get input from the user therefore we represent the input in a vector.
 * @param sizeOfFilter The size of the Bloom filter array.
 * @param Hashes The functions for the Bloom filter.
 */
BloomFilter::BloomFilter(unsigned long sizeOfFilter, const vector<int>& Hashes){
    bloomFilterSize = sizeOfFilter;
    // For each int in the vector we get we check if it's function 1 or function 2 and work accordingly.
    for (int func : Hashes) {
        switch (func) {
            case 1:
                hashFunctions.push_back(new HashOnce);
                break;
            case 2:
                hashFunctions.push_back(new HashTwice);
                break;
            default:
                throw invalid_argument("invalid argument");
        }
    }
    // Initializing filter.
    filter = vector<bool>(bloomFilterSize);
}

// Getting the blacklisted urls in a vector format.
vector<string> BloomFilter::getUrlBlacklist(){
    return urlBlacklist;
}

/**
 * Adding a url to the blacklist.
 * @param addedUrl The url we want to add.
 */
void  BloomFilter::addUrl(string addedUrl) {
    // add current url to blacklist (list of explicit urls).
    urlBlacklist.push_back(addedUrl);

    // Perform hashing to url using all functions of current filter and add them to the bloom filter.
    unsigned long hashedUrl = 0;
    for (HashFunction* hash : hashFunctions) {
        if (hashedUrl == 0) {
            hashedUrl = hash->hashURL(addedUrl);
        } else {
            hashedUrl = hash->hashURL(to_string(hashedUrl));
        }
        unsigned long hashedIndex = hashedUrl % bloomFilterSize;
        filter[hashedIndex] = true;
    }
}

/**
 * Checking if the url is blacklisted.
 * @param checkedUrl The url we want to check.
 */
string BloomFilter::checkIfBlacklisted(string checkedUrl){
    string answer = "false";
    unsigned long hashedUrl = 0;
    for (HashFunction* hash : hashFunctions) {
        if (hashedUrl == 0) {
            hashedUrl = hash->hashURL(checkedUrl);
        } else {
            hashedUrl = hash->hashURL(to_string(hashedUrl));
        }
        unsigned long hashedIndex = hashedUrl % bloomFilterSize;
        if(!filter[hashedIndex]) {
            return answer;
        }
    }
    answer = "true ";
    // Iterate through blacklist, and search for checked url.
    for(const string& s : getUrlBlacklist()) {
        if (s == checkedUrl) {
            answer += "true";
            return answer;
        }
    }
    answer += "false";
    return answer;
}

/**
 * Destructor for Bloom filter.
 */
BloomFilter::~BloomFilter() {
    // Destroying each hash function.
    for (HashFunction* hash : hashFunctions) {
        delete hash;
    }
}