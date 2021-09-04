#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n)
{
	int i,key,j;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j >=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

/*
void insertionSortRec(int arr[],int n)
{
	if(n<=1)
		return;
	insertionSortRec(arr,n-1);
	int last=arr[n-1];
	int j=n-2;
	
	while(j>=0 && arr[j]>last)
	{
		arr[j+1]=arr[j];
		j--;	
	}
	arr[j+1]=last;
}
*/