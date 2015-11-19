//
//  usa_states_map.cpp
//
//  Created by Masatoshi Nishiguchi on 11/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//


#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * Class that represents a node
 */
class UsaState {
public:
    // Constructors
    UsaState(string stateName);
    
    string stateName;
    int population;
    string stateFlower;
    
    UsaState* next;
};


/**
 *  Constructor to create a node with a specific set of data
 */
UsaState::UsaState(string stateName) {
    next = NULL;
    
    this->stateName   = stateName;
    this->population  = 0;
    this->stateFlower = "";
}

// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Hash function based on the algorithm used in Java.
 * http://stackoverflow.com/questions/15518418/whats-behind-the-hashcode-method-for-string-in-java
 * h(s) = s[0]   * 31^(n-1)
 *      + s[1]   * 31^(n-2)
 *      + ...
 *      + s[n-1] * 31^(n-n)
 *   # s[i] denotes the ith character of the string
 *   # n is the length of s
 * https://en.wikipedia.org/wiki/Java_hashCode()
 * ==
 * @param
 * @param
 * @return
 */
int hashFunc(string key) {
    
    int hash = 0;
    int len  = (int)key.length();
    
    for (int i = 0; i < len; i++) {
        
        hash += key[0] * pow( 31, (len - i) );
        
    }
    
    return hash;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {
    
    // Create an array to be used as a hash map
    UsaState* hashStates[11];
    
    //
    UsaState* curr;
    curr = new UsaState("PA");  // Could hash to 0..10
    
    int theHash = hashFunc(curr->stateName);
    
    cout << "hashed: " << theHash << endl;
    
    
    return 0;
}
