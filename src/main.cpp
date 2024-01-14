//
// Created by DELL on 14/01/2024.
//
#include <string>
#include <iostream>
#include <vector>
#include "BloomFilter.h"
using namespace std;
int main(int argc, char** argv){


    int task;
    cin >> task;
    while (true){
    switch(task) {
        case (1): {
            string url;
            cin >> url;
           // bloom_filter.add_url(url);
        }

        case (2): {
      //      bloom_filter.check_if_blacklisted(url);
        }
        default: {
            cout << "Invalid task" << endl;
        }

    }
}







}
