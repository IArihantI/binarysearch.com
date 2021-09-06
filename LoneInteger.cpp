//
//  LoneInteger.cpp
//  
//
//  Created by Arihant on 9/6/21.
//
int solve(vector<int>& nums) {
    int ans = 0;
    int i = 0;
    while(i < 32){
        int countSetBits = 0;
        for(int n: nums){
            if((n >> i) & 1)countSetBits++;
        }
        if(countSetBits % 3 != 0){
            ans += (1 << i);
        }
        i++;
    }
    return ans;
}
