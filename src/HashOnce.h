//
// Created by DELL on 14/01/2024.
//

#ifndef PART1ASP_HASHONCE_H
#define PART1ASP_HASHONCE_H
#pragma once
#include "HashFunction.h"
#include <string>

using namespace std;
class HashOnce: public HashFunction {
public:
    long hash_url(string url) override;
};
#endif //PART1ASP_HASHONCE_H