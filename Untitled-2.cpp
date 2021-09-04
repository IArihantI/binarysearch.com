#include <bits/stdc++.h>
using namespace std;
int solve(int arr[],int n,int target){
    int flag=0;
    int pos;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        {
           return i;
        }
        if(arr[i]>target)
        {
            if(i==0)
			return 0;
			else
			return i;
        }
    }
    return n;
}
int main() {
	int n;
	int arr[]={1,3,5,6};
	//for(int i=0;i<n;i++)
	//cin>>arr[i];
	n=sizeof(arr)/sizeof(arr[0]);
	int target=7;
	cout<<solve(arr,n,target)<<endl;
	return 0;
}