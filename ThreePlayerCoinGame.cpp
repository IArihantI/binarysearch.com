//
//  ThreePlayerCoinGame.cpp
//  
//
//  Created by Arihant on 9/5/21.
//

#include <stdio.h>
int solve(vector<int>& piles) {
    int i = 0, j = piles.size() - 2, ans = 0;
    sort(piles.begin(),piles.end());
    while(i < j){
        ans += piles[j];
        i++;
        j -= 2;
    }
    return ans;
}
