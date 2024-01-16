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
int main(int argc, char** argv){
    /**
     * The type of task we get.
     * 1: Add url to the blacklist.
     * 2: Check if the url is blacklisted.
     */
    string temp_task;
    int task = 0;
    // The url we get.
    string url;
    // Initializing the Bloom filter.
    BloomFilter filter = BloomFilter();

    // Looping to wait for the user to input the task and url.
    while (true){
        /**
         * Getting both the task (int 1/2) and the url (string)
         */
        cin >> temp_task;
        try {
            if (stoi(temp_task) == 1 || stoi(temp_task) == 2) {
                task = stoi(temp_task);
            } else {
                continue;
            }
        } catch (exception e) {
            // In case temp_task isn't int.
            continue;
        }
        // Switching depending on the value of the task.
        cin >> url;
        switch(task) {

            case 1: {
                // Adding the url to the blacklist.
                filter.add_url(url);
                break;
            }

            case 2: {
                // Checking if the url is blacklisted.
                cout << filter.check_if_blacklisted(url) << endl;
                break;
            }

            default: {
                // We got a value we shouldn't get, so we tell that to the user and try again.
                cout << "You shouldn't get here!!!";
            }
        }
    }
}