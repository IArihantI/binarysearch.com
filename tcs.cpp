#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n=s1.size();
    int m=s2.size();
    int ans=0;
    unordered_map<char,int> m;
    for(int i=0;i<n;i++)
    {
        m[s1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        if(m[s2[i]])
        m[s2[i]]--;
    }
    for(auto a:m)
    { 
        if(a.second)
            ans+=a.second;
    }
    cout<<ans<<endl;
}