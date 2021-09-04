#include<bits/stdc++.h>
using namespace std;
int expandFromMiddle(string s,int left,int right)
{
    if( left>right) return 0;
    while(left>=0 && right<s.length()&& s[left]==s[right])
    {
        left--;
        right++;
    }
    return right-left-1;
}
string solve(string str){
    if( str.length()<1)return "";
    int start=0;
    int end=0;
    for(int i=0;i<str.length();i++)
    {
        int len1=expandFromMiddle(str,i,i);
        int len2=expandFromMiddle(str,i,i+1);
        int len=max(len1,len2);
        if(len>end-start)
        {
            start=i-((len-1)/2);
            end=i+(len/2);
        }
    }
    return str.substr(start,end+1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout<<solve(str)<<endl;
    }
}