#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int arrayRotation(int arr[],int d,int n)
{
	int g_c_d=gcd(n,d);
	int temp;
	for(int i=0;i<g_c_d;i++)
	{
		int temp=arr[i];
		int j=i;

		while(1){
			k=j+d;
			if(k>=n)
				k-=n;
			if(k==i)
				break;
			arr[j]=arr[k];
			j=k;
		}
		arr[j]=temp;
	}
}