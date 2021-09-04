#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string frwd=s[s.size()-1]+s.substr(0,s.size()-1);
    string bckwrd=s.substr(1,s.size())+s[0];
    if(frwd==bckwrd)
    cout<<1<<endl;
    else
    cout<<0<<endl;
}