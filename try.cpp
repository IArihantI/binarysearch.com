#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int max_val=arr[0];
	int min_val=arr[0];
	int ans=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]<0)
			swap(max,min);
		max_val=max(arr[i]*max_val,arr[i]);
		min_val=min(arr[i]*min_val,arr[i]);

		ans=max(ans,max_val);
	}
	return ans;
}