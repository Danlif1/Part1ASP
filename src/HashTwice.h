//
// Created by DELL on 14/01/2024.
//

#ifndef PART1ASP_HASHTWICE_H
#define PART1ASP_HASHTWICE_H
#pragma once
#include "HashFunction.h"
#include <string>
using namespace std;
class HashTwice: public HashFunction {
public:
    long hash_url(string url);
};
#endif //PART1ASP_HASHTWICE_H
