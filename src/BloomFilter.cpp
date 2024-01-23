//
// Created by Itamar Berger, Daniel Lifshitz
//

#include "BloomFilter.h"

using namespace std;

/**
 * Bloom filter constructor for manual run.
 */
BloomFilter::BloomFilter(){
    // Initializing the size of the bloom filter and the hashes.
    string tempBloomFilter;
    vector<int> hashes;
    hashes.clear();
    // Getting the size of the bloom filter and the hashes.
    while (!bloomFilterSize || hashes.empty()) {
        // Getting the line.
        getline(cin,tempBloomFilter);

        // constructing stream from the string.
        stringstream ss(tempBloomFilter);
        std::vector<int> usedHashes = {};
        // clearing the vector to store the string after split in case we got a wrong input before.
        hashes.clear();

        // A boolean for our first input (The Bloom filter size).
        bool first = true;
        // using while loop until the getline condition is satisfied
        // ' ' represent split the string whenever a space is found in the original string
        while (getline(ss, tempBloomFilter, ' ')) {
            // The Bloom filter size.
            if (first) {
                try {
                    bloomFilterSize = stoul(tempBloomFilter);
                } catch (exception e) {
                    bloomFilterSize = 0;
                    break;
                }
                first = false;
            }
            // The hashes vector.
            else {
                try {
                    // store token string in the vector
                    int func = stoi(tempBloomFilter);
                    if (func == 1 || func == 2) {
                        bool flag = false;
                        for (int hash : usedHashes) {
                            if (func == hash) {
                                flag = true;
                            }
                        }
                        if (!flag) {
                            hashes.push_back(func);
                            usedHashes.push_back(func);
                        }
                    } else {
                        bloomFilterSize = 0;
                        break;
                    }
                } catch (exception e) {
                    bloomFilterSize = 0;
                    break;
                }
            }
        }
    }
    // Iterate the hashes vector for our bloom filter.
    for (int func : hashes) {
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
void  BloomFilter::addUrl(const string& addedUrl) {
    // add current url to blacklist (list of explicit urls).
    urlBlacklist.push_back(addedUrl);

    // Perform hashing to url using all functions of current filter and add them to the bloom filter.
    for (HashFunction* hash : hashFunctions) {
        unsigned long hashedUrl = hash->hashURL(addedUrl);
        unsigned long hashedIndex = hashedUrl % bloomFilterSize;
        filter[hashedIndex] = true;
    }
}

/**
 * Checking if the url is blacklisted.
 * @param checkedUrl The url we want to check.
 */
string BloomFilter::checkIfBlacklisted(const string& checkedUrl){
    string answer = "false";
    for (HashFunction* hash : hashFunctions) {
        unsigned long hashedUrl = hash->hashURL(checkedUrl);
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

void BloomFilter::run() {
    /**
     * The type of task we get.
     * 1: Add url to the blacklist.
     * 2: Check if the url is blacklisted.
     */
    string tempTask;
    int task = 0;
    // The url we get.
    string url;
    // Looping to wait for the user to input the task and url.
    while (true){
        /**
         * Getting both the task (int 1/2) and the url (string)
         */
        cin >> tempTask;
        try {
            if (stoi(tempTask) == 1 || stoi(tempTask) == 2) {
                task = stoi(tempTask);
            } else {
                continue;
            }
        } catch (exception e) {
            // In case tempTask isn't int.
            continue;
        }
        // Switching depending on the value of the task.
        cin >> url;
        switch(task) {

            case 1: {
                // Adding the url to the blacklist.
                addUrl(url);
                break;
            }

            case 2: {
                // Checking if the url is blacklisted.
                cout << checkIfBlacklisted(url) << endl;
                break;
            }

            default: {
                // We got a value we shouldn't get, so we tell that to the user and try again.
                cout << "You shouldn't get here!!!";
            }
        }
    }
}
