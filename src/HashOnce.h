//
// Created by DELL on 14/01/2024.
//

#ifndef PART1ASP_HASHONCE_H
#define PART1ASP_HASHONCE_H

#include "HashFunction.h"

using namespace std;

// It's a hash function, so it inherits from HashFunction.
class HashOnce: public HashFunction {
    public:
        unsigned long hash_url(string url) override;
        ~HashOnce() = default;
};

#endif //PART1ASP_HASHONCE_H