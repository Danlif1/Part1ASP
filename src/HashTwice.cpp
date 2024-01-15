//
// Created by DELL on 14/01/2024.
//

#include <string>
#include "HashFunction.h"
#include "HashTwice.h"

using namespace std;
     long HashTwice:: hash_url(string url)  {
        // Use standard hash and hash url twice.
        std::hash <string> hasher;
        return hasher(to_string(hasher(url)));
    }
