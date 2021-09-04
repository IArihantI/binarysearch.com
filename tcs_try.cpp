#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	arr[0]=0,arr[1]=0,arr[2]=2,arr[3]=1;
	for(int i=4;i<n;i++)
	{
		if(i%2==0)
		arr[i]=i;
		else
		arr[i]=i-2;
	}
	cout<<arr[n-1]<<endl;
	return 0;
}