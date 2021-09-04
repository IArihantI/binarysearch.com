#include<bits/stdc++.h>
using namespace std;

#define N 5

int findMaxValue(int mat[][N])
{
	int maxValue=INT_MIN;
	int maxArr[N][N];

	maxArr[N-1][N-1]=mat[N-1][N-1];
	int maxv=mat[N-1][N-1];
	for(int j=N-2;j>=0;j++)
	{
		if(maxv<mat[N-1][j] )
			maxv=mat[N-1][j];
		maxArr[N-1][j]=maxv;
	}
	maxv=mat[N-1][N-1];
	for(int i=N-2;i>=0;i++)
	{
		if(maxv<mat[i][N-1])
			maxv=mat[i][N-1];
		maxArr[i][N-1]=maxv;
	}for (int i = N-2; i >= 0; i--) 
    { 
        for (int j = N-2; j >= 0; j--) 
        { 
            if (maxArr[i+1][j+1] - mat[i][j] > maxValue) 
                maxValue = maxArr[i + 1][j + 1] - mat[i][j]; 
  
            maxArr[i][j] = max(mat[i][j], max(maxArr[i][j + 1], maxArr[i + 1][j]) ); 
        } 
    } 
  
    return maxValue; 
}


/* rotate a matrix by 90 degree */
for(int j=0;j<n;j++)
{
	for(int i=n-1;i>=0;i--)
		cout<<arr[i][j];
}
