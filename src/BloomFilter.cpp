//
// Created by Itamar Berger
//
#include <string>
#include <iostream>
#include <vector>
#include "HashOnce.cpp"
#include "HashTwice.cpp"
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
            filter = vector<bool>(bloom_filter_size);
            int num_of_func,i;
            while(cin>>num_of_func){

                if(num_of_func==1){
                    hash_functions.push_back(new HashOnce());
                }
                else{
                    if(num_of_func==2) {
                        hash_functions.push_back(new HashTwice());
                    }
                    else{
                        cout<<"wrong function key - try again"<<endl;
                    }
                }
                i--;
        }
    }


    long add_url(string added_url) {
           // resize vector of blacklist urls, and add current url to list.
            this->url_blacklist.resize(url_blacklist.capacity()+1);
            this->url_blacklist[url_blacklist.size()-1]=added_url;
            // Perform hashing to url using all functions of current filter.
            long hashed_url;
            // Perform upon url all user's hash functions.
            for(int i=0;i<this->hash_functions.size();i++){
                 hashed_url = this->hash_functions[i]->hash_url(added_url);
            }
            // Check if hashed index is 0 and flip its bit. o.w - do nothing.
            long hashed_index = hashed_url%this->filter.size();
            if(!this->filter[hashed_index]){
                this->filter[hashed_index] = true;
            }
            return true;
            }




};