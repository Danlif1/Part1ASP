//
// Created by DELL on 14/01/2024.
//
#include "BloomFilter.h"

using namespace std;

/**
 * The main function that runs the entire code,
 * We don't get input from the program variables,
 * And we don't return anything in the end.
 */
//int main(int argc, char** argv){
//    /**
//     * The type of task we get.
//     * 1: Add url to the blacklist.
//     * 2: Check if the url is blacklisted.
//     */
//    int task;
//    // The url we get.
//    string url;
//    // Initializing the Bloom filter.
//    BloomFilter filter = BloomFilter();
//
//    // Looping to wait for the user to input the task and url.
//    while (true){
//        /**
//         * Getting both the task (int 1/2) and the url (string)
//         */
//        cin >> task >> url;
//
//        // Switching depending on the value of the task.
//        switch(task) {
//
//            case (1): {
//                // Adding the url to the blacklist.
//                filter.add_url(url);
//                break;
//            }
//
//            case (2): {
//                // Checking if the url is blacklisted.
//                cout << filter.check_if_blacklisted(url) << endl;
//                break;
//            }
//
//            default: {
//                // We got a value we shouldn't get, so we tell that to the user and try again.
//                cout<<"invalid input, please try again";
//            }
//        }
//    }
//}

int main() {
    BloomFilter filter = BloomFilter(256, {1, 2});
    filter.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    std::cout << filter.check_if_blacklisted("www.example.com") << endl;

    BloomFilter filter2 = BloomFilter(1,{1,2});
    filter2.add_url("www.example.com");
    std::cout << filter2.check_if_blacklisted("www.example.com1") << endl;

    BloomFilter filter3 = BloomFilter(256,{1,2});
    filter3.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    std::cout << filter3.check_if_blacklisted("www.example.com1") << endl;

    BloomFilter filter4 = BloomFilter(256,{1,2,1,2,1,1,1,2});
    filter4.add_url("www.example.com");
    // Check if added url appears on explicit urls blacklist.
    std::cout << filter4.check_if_blacklisted("www.example.com1") << endl;

    BloomFilter filter5 = BloomFilter(5,{1,2,1,2,1,1,1,2});
    filter5.add_url("www.example.com");
    filter5.add_url("www.example.com2");
    filter5.add_url("www.example.com3");
    filter5.add_url("www.example.com4");
    filter5.add_url("www.example.com6");

    // Check if added url appears on explicit urls blacklist.
    std::cout << filter5.check_if_blacklisted("www.example.com1") << endl;


}