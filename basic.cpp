#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s="abzx",ans="";
    int n=s.size();
    int arr[26]={0};
    for(int i=0;i<s.size();i++)
    {
        arr[s[i]-'a']++;
    }
    for(int i=0;i<s.size();i++)
    {   
        if(arr[s[i]-'a']!=-1)
        {
            if(s[i]<='i')
            {
                ans+=(int)(s[i]-'a');
            }
            else
                ans+=(int)(s[i]-'a')+'#';
            if(arr[s[i]-'a']>1)
            {
                ans+='('+arr[s[i]-'a']+')';
                arr[s[i]-'a']=-1;
            }
        }
    }
    cout<<ans<<endl;
}