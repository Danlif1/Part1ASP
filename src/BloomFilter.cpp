//
// Created by Itamar Berger
//
#include <string>
#include <iostream>
#include <vector>
#include "HashOnce.cpp"
#include "HashTwice.cpp"
#include <stdexcept>
using namespace std;
class BloomFilter {

    private:
         vector<bool>filter;
         vector<string> url_blacklist;
         // array of functions used for filtering urls to blacklist.
         vector<HashFunction*> hash_functions;
    public:
         BloomFilter(){
             int bloom_filter_size;
             cin>>bloom_filter_size;
             // Initial an array of bits to represent a bloom filter.
            filter = vector<bool>(bloom_filter_size);
            int num_of_func;
            // Iterate while user is typing hash functions for our bloom filter.
             while (cin.get() != '\n'){
                 cin>>num_of_func;
                if(num_of_func==1){
                    hash_functions.push_back(new HashOnce());
                }
                else{
                    if(num_of_func==2) {
                        hash_functions.push_back(new HashTwice());
                    }
                    else{
                        throw invalid_argument("invalid argument");
                    }
                }
        }
    }
    BloomFilter(int size_of_filter,int func1, int func2){
        if (func1 == 1) {
            this->hash_functions.push_back(new HashOnce);
        } else {
            this->hash_functions.push_back(new HashTwice);
        }
        if (func2 == 1) {
            this->hash_functions.push_back(new HashOnce);
        } else {
            this->hash_functions.push_back(new HashTwice);
        }
        this->filter =  vector<bool>(size_of_filter);
    }
    vector<string> get_url_blacklist(){
             return this->url_blacklist;
         }

    void add_url(string added_url) {
           // add current url to blacklist (list of explicit urls).
            this->url_blacklist.push_back(added_url);

            // Perform hashing to url using all functions of current filter.
            long hashed_url = this->hash_url_using_all_functions(added_url);

            // Check - if hashed index is 0, flip its bit. o.w - do nothing.
            long hashed_index = hashed_url%this->filter.size();
            if(!this->filter[hashed_index]){
                this->filter[hashed_index] = true;
            }
         }

            void check_if_blacklisted(string checked_url){
            long hashed_url = this->hash_url_using_all_functions(checked_url);
            long hashed_index = hashed_url%this->filter.size();
                // If bloom filter is off at hashed_index - print false.
                if(!this->filter[hashed_index]) {
                    cout<<"false"<<endl;
                    return;
                }
                cout<<"true ";
                // Iterate through blacklist, and search for checked url.
                for(string s : this->get_url_blacklist()){
                  if(s == checked_url){
                      cout<<"true"<<endl;
                      return;
                  }
                    cout<<"false"<<endl;
                  return;
                }
                }

         long hash_url_using_all_functions(string url){
             long hashed_url;
             // Perform upon url all user's hash functions.
             for(int i=0;i<this->hash_functions.size();i++){
                 hashed_url = this->hash_functions[i]->hash_url(url);
                 url = to_string(hashed_url);
             }
             return hashed_url;
         }
};