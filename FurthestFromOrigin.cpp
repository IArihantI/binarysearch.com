//
//  FurthestFromOrigin.cpp
//  
//
//  Created by Arihant on 9/6/21.
//
int solve(string s) {
    int left = 0, right = 0, a = 0;
    for(char ch: s){
        if(ch == 'L')
            left++;
        else if(ch == 'R')
            right++;
        else{
            a++;
        }
    }
    return a + abs(left - right);
}
