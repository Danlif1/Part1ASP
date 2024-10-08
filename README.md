# Part1ASP

## Made by Daniel Lifshitz, Itamar Berger (Before he got צו 8), Yishai Nisim (Who was exempted from this part)

### In this part we implemented a Bloom filter algorithm.

In this part, we used a Bloom filter as a fast way to check if a given URL is blacklisted.
A Bloom filter can return false positives so we used a normal check in case of a positive to check if it's a false positive.

## Src

### BloomFilter.h/cpp

In this file we hold all the functions Bloom filter use, checking if a URL is blacklisted, blacklisting a URL, constructing the Bloom filter, getting all blacklisted URLs, and destroying the Bloom filter.

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

Holds the code for the docker.
And the auto tests.

## Not in a folder.

### CMakeLists.txt

Holds the code for the compiler to run tests, and the code to run the code manually.

### Dockerfile

Holds the code to tell the cd.yml file what to do.

## How to run.

### Manually

```
cmake -B build -S .                       
cmake --build build
./build/MainExecutable
```

### Tests

```
cmake -B build -S .                       
cmake --build build
ctest --test-dir build --output-on-failure
```
or

```
cmake -B build -S .                       
cmake --build build
./build/BloomFilterTests
```

## Jira

We worked with Jira to document our progress with each step.

## TDD

I'm not sure how my partner worked with it because he left before I was able to ask,
But what I did was to run the tests on my computer and if it worked to push it into GitHub and if it also worked, to add more tests until I was positive my code worked perfectly.
It helped me catch the bug where hash returns unsigned long and my partner used long.

## Docker Hub

I used the docker hub to hold a dockerized version of my code.
