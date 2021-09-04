#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n)
{
    int right_suffix_arr[n];
    right_suffix_arr[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right_suffix_arr[i]=max(arr[i],right_suffix_arr[i+1]);
    }
    int sum=0;
    set<int> s;
    s.insert(arr[0]);
    for(int j=1;j<n;j++)
    {
        s.insert(arr[j]);
        if(arr[j]>=right_suffix_arr[j+1])continue;
        auto it=s.find(arr[j]);
        if(it==s.begin())continue;
        it--;
        sum=max(sum,(*it+arr[j]+right_suffix_arr[j+1]));
    }
    return sum;
}

int main()
{
    int arr[7]={2,5,3,6,1,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    //solve(arr,n);
    int res=solve(arr,n);
    cout<<res<<endl;
    return 0;
}