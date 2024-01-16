//
// Created by DELL on 14/01/2024.
//

#include "HashOnce.h"

/**
 * Hashing once (h1).
 * @param url The url we want to hash.
 * @return The hashed version of the url.
 */
unsigned long HashOnce:: hash_url(string url){
    // Use standard hash and hash url once
    std::hash<string> hasher;
    return hasher(url);
}