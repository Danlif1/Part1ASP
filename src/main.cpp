//
// Created by DELL on 14/01/2024.
//
#include <string>
#include <iostream>
#include "BloomFilter.cpp"
using namespace std;
int main(int argc, char** argv){


    int task;
    string url;
    BloomFilter filter = BloomFilter();
    cin>>task;

    while (true){
    switch(task) {
        case (1): {
            cin >> url;
            filter.add_url(url);
            cin>>task;
            break;
        }

        case (2): {
            cin >> url;
             filter.check_if_blacklisted(url);
            cin>>task;
            break;
        }
        default: {
            cout<<"invalid input, please try again";
        }
    }
}
}
