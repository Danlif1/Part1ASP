//
// Created by Itamar Berger, Daniel Lifshitz
//
#include "BloomFilter.h"

using namespace std;

/**
 * The main function that runs the entire code,
 * We don't get input from the program variables,
 * And we don't return anything in the end.
 */
int main(int argc, char** argv){
    // Initializing the Bloom filter.
    BloomFilter filter = BloomFilter();
    // Running the filter.
    filter.run();
}