//
// Created by DELL on 14/01/2024.
//

#ifndef PART1ASP_HASHTWICE_H
#define PART1ASP_HASHTWICE_H

#include "HashFunction.h"

using namespace std;

// It's a hash function, so it inherits from HashFunction.
class HashTwice: public HashFunction {
    public:
        long hash_url(string url);
};

#endif //PART1ASP_HASHTWICE_H
