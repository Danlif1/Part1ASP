//
// Created by DELL on 14/01/2024.
//

#include "HashFunction.h"
#include "HashOnce.h"

        long  HashOnce:: hash_url(string url){
            // Use standard hash and hash url once
            std::hash<string> hasher;
            return hasher(url);
    }