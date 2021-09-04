#include<bits/stdc++.h>
using namespace std;

int missingNumber(int arr[],int n)
{	
	int a=1;
	for(int i=2;i<=n+1;i++)
		a=a^i;
	int x=a[0];
	for(int i=1;i<n;i++)
		x=x^a[i];
	return a^x;
}