#include<bits/stdc++.h>
using namespace std;
int m=4,n=4;
void spiral(int matrix[m][n])
{
    int i,k=0,l=0;
    while(k<m && l<n)
    {
        for(i=l;i<n;i++)
        {
            cout<<matrix[k][i]<<" ";
        }
        k++;
        for(i=k;i<m;i++)
        {
            cout<<matrix[i][n-1]<<" ";
        }
        n--;
        if(k<m)
        {
            for(i=n-1;i>=l;i--)
            {
                cout<<matrix[m-1][i]<<" ";
            }
            m--;
        }
        if(l<n){
            for(int i=m-1;i>=k;i--)
            {
                cout<<matrix[i][l]<<" ";
            }
            l++;
        }
    }
}
int main()
{
    int mat[][4]={{1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}};
    spiral(mat);
    cout<<endl;
    return 0;
}

