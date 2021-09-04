#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{
	return abs(a) < abs(b);
}
void findMinSum(int arr[],int n)
{
	sort(arr,arr+n);
	int min=INT_MAX,x,y;
	for(int i=1;i<n;i++)
	{
		if(abs(arr[i]-arr[i-1]) <=min){
			min=abs(arr[i]-arr[i-1]);
			x=i-1;
			y=i;
		}
	}
	cout<<arr[x]<<" "<<arr[y]<<endl;
}