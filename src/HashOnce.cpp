//
// Created by DELL on 14/01/2024.
//

#include "HashFunction.h"
#include "HashOnce.h"

class HashOnce: public HashFunction{
    public:
        long hash_url(string url) override{
            // Use standard hash and hash url once
            std::hash<string> hasher;
            return hasher(url);
    }
};