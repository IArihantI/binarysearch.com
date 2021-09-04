#include<bits/stdc++.h>
using namespace std;
static bool comp(pair<int,int> &a,pair<int,int> &b)
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second>b.second;
}
vector<int> frequency(vector<int>& A)
{
    unordered_map<int,int> nums;
    for(int num:A)
    nums[num]++;
    vector<pair<int,int>> vec;
    for(auto p:nums)
        vec.push_back(p);
    sort(vec.begin(),vec.end(),comp);
    vector<int> ans{};
    for(auto p:vec)
    {
        while(p.second--)
            ans.push_back(p.first);
    }
    return ans;
    
}