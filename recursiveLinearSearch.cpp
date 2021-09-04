#include<bits.stdc++.h>
using namespace std;

int recursiveLinearSearch(int arr[],int l,int r,int x)
{
	if(r<l)
		return -1;
	if(arr[r]==x)
		return r;
	if(arr[l]==x)
		return l;
	return recursiveLinearSearch(arr,l+1,r-1,x);
}
