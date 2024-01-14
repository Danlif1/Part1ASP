//
// Created by DELL on 14/01/2024.
//

#include <string>
#include "HashFunction.h"

using namespace std;
class HashTwice: public HashFunction {
public:
     long hash_url(string url) override {
        // Use standard hash and hash url twice.
        std::hash <string> hasher;
        return hasher(to_string(hasher(url)));
    }
};