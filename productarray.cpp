#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int a)
{   
    int n=a;
    int left[n+1],right[n+1];
    //left[0]=1;
    //right[n-1]=arr[n-1];
    for(int i=0;i<n+1;i++){
        left[i]=1;
        right[i]=1;
    }
    for(int i=1;i<n;i++)
    left[i]=left[i-1]*arr[i];
    for(int i=n-1;i>=0;i--)
    right[i]=right[i+1]*arr[i];
    for(int i=0;i<n;i++)
    cout<<left[i-1]*right[i+1]<<" ";
    cout<<endl;
}
int main()
{
    int n=5;
    int arr[]={1,2,3,4,5};
    solve(arr,n);
    return 0;
}