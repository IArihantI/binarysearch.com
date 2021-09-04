//
//  PeekableIterator.cpp
//  
//
//  Created by Arihant on 9/5/21.
//

#include <stdio.h>
class PeekableIterator {
    public:
    vector<int>::iterator a, b;
    vector<int> arr;
    PeekableIterator(vector<int>& arr) : arr(move(arr)){
        a = this -> arr.begin();
        b = this -> arr.end();
    }

    int peek() {
        return(*a);
    }

    int next() {
        return (*a++);
    }

    bool hasnext() {
        return ( a != b );
    }
};
