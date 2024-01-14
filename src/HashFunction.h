//
// Created by DELL on 14/01/2024.
//

#ifndef PART1ASP_HASHFUNCTION_H
#define PART1ASP_HASHFUNCTION_H
#pragma once
#include <string>
using namespace std;
class HashFunction{
public:
    virtual long hash_url(string url) = 0;
};
#endif //PART1ASP_HASHFUNCTION_H
