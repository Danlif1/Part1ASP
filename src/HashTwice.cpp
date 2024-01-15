//
// Created by DELL on 14/01/2024.
//


#include "HashTwice.h"

using namespace std;

/**
 * Hashing twice (h2).
 * @param url The url we want to hash.
 * @return The hash value of the url hashed twice.
 */
long HashTwice:: hash_url(string url)  {
    // Use standard hash and hash url twice.
    std::hash <string> hasher;
    return hasher(to_string(hasher(url)));
}
