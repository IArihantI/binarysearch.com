#include<bits/stdc++.h>
using namespace std;

int subsetSum_knapsack(int arr[],int sum,int n)
{
	int t[n+1][sum+1];
	for(int i=0;i<n+1;i++)
		t[i][0]=1;
	for(int j=1;j<sum+1;j++)
		t[0][j]=0;
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(arr[i-1]<=j)
			{
				t[i][j]=max(t[i-1][j-arr[i-1]],t[i-1][j]);
			}
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
}
int main()
{
	int arr[]={2,3,7,8,10};
	int n=5;
	int sum=11;
	int res=subsetSum_knapsack(arr,sum,n);
	if(res)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}