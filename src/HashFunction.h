//
// Created by Itamar Berger, Daniel Lifshitz
//

#ifndef PART1ASP_HASHFUNCTION_H
#define PART1ASP_HASHFUNCTION_H

#include <string>

using namespace std;

/**
 * The parent of all hash functions.
 */
class HashFunction {
public:
    virtual unsigned long hashURL(string url) = 0;
    virtual ~HashFunction() = default;
};

#endif //PART1ASP_HASHFUNCTION_H
