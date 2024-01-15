# Part1ASP

## Made by Daniel Lifshitz, Itamar Berger (Before he got צו 8), Yishai Nisim (Who was exempted from this part)

### In this part we implemented Bloom filter.

In this part we used a Bloom filter for a fast way to check if a given url is blacklisted.
A Bloom filter can return false positives so we used a normal check in case of a positive to check if its a false positive.

## Src

### BloomFilter.h/cpp

In this file we hold all the functions bloom filter use, checking if a url is blacklisted, blacklisting a url, constructing url, and getting all blacklisted urls.

### HashFunction.h

This is the template for every hash function we want to create.

### HashOnce.h/cpp

A hash function that calls std::hash once.

### HashTwice.h/cpp

A hash function that calls std::hash twice.

### main.cpp

The main function, in case you want to run the code without the tests, and through the terminal.

## Tests

### BloomFilter_test.cpp

All the tests for the Bloom filter.

### test_main.cpp

The main function of the tests.

## .github

holds the code for the docker.

## Not in folder.

### CMakeLists.txt

Holds the code for the compiler to run using tests.
If you want to run the code through the terminal without tests go to the file and all the code without # turn to # and all the code with # turn to without.
