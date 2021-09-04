#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>arr)
{
    map<set<pair<int,int>>,int>s;
    for(int i=0;i<arr.size()-1;i++)
        s[make_pair(arr[i],arr[i+1])]++;
    for(auto c:s)
    {
        if(s[c] > 1)
        {
            cout<<c.first<<" "<<c.second<<endl;
        }
    }
}
int main()
{
    int n=5;
    vector<int>arr{1,2,3,1,2};
    solve(arr);
    return 0;
}
