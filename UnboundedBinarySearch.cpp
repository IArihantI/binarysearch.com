#include<bits/stdc++.h>
using namespace std;

int f(int x){return (x*x-10*x-20);}

int binarySearch(int low,int high);

int findFirstPositive()
{
	if(f(0)>0)
		return 0;
	int i=1;
	while(f(i)<=0)
		i*=2;
	return binarySearch(i/2,i);
}
int binarySearch(int low,int high)
{
	if(high >= low)
	{
		int mid=low+(high-low)/2;
		if(f(mid)>0 &&(mid == low || f(mid-1)<=0))
			return mid;
		if(f(mid)<=0)
			return binarySearch(mid+1,high);
		else
			return binarySearch(low,mid-1);
	}
	return -1;

}