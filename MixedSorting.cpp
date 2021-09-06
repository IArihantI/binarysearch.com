//
//  MixedSorting.cpp
//  
//
//  Created by Arihant on 9/6/21.
//

vector<int> solve(vector<int>& nums) {
    vector<int> even, odd;
    for(int i: nums){
        if(i % 2 == 0){
            even.push_back(i);
    }
    else{
        odd.push_back(i);
    }
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end(),greater<int>());
    vector<int> ans;
    int count_even = 0, count_odd = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % 2 == 0){
            ans.push_back(even[count_even++]);
        }
        else{
            ans.push_back(odd[count_odd++]);
        }
    }
    return ans;
}
