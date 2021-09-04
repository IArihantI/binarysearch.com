#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n)
{
    int a;
    if(n%2==0)
    a=n/2-1;
    else
    a=n/2;
    for(int i=0;i<=a;i++)
    swap(arr[i],arr[n-i-1]);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    solve(arr,n);
    return 0;
}