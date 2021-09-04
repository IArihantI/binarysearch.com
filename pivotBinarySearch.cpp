#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int low,int high,int x)
{
	if(high < low)
		return -1;
	int mid=low+(high-low)/2;
	if(arr[mid]==x)
		return mid;
	if(arr[mid]>x)
		return binarySearch(arr,low,mid-1,x);
	return binarySearch(arr,mid+1,high,x);
}
int findPivot(int arr[],int low,int high)
{
	if(high<low)
		return -1;
	if(high==low)
		return low;
	int mid=low+(high-low)/2;
	if(mid<high && arr[mid]>arr[mid+1])
		return mid;
	if(mid>low && arr[mid]<arr[mid-1])
		return mid-1;
	if(arr[low]>=arr[mid])
		return findPivot(arr,low,mid-1);
	return findPivot(arr,mid+1,high);
}
int pivotBinarySearch(int arr[],int n,int key)
{
	int pivot=findPivot(arr,0,n-1);
	if(pivot==-1)
		binarySearch(arr,0,n-1,key);
	if(arr[pivot]==key)
		return pivot;
	if(arr[0]<=key)
		return binarySearch(arr,0,pivot-1,key);
	return binarySearch(arr,pivot+1,n-1,key);

}
/*
Input arr[] = {3, 4, 5, 1, 2}
Element to Search = 1
  1) Find out pivot point and divide the array in two
      sub-arrays. (pivot = 2) Index of 5
  2) Now call binary search for one of the two sub-arrays.
      (a) If element is greater than 0th element then
             search in left array
      (b) Else Search in right array
          (1 will go in else as 1 < 0th element(3))
  3) If element is found in selected sub-array then return index
     Else return -1.

*/