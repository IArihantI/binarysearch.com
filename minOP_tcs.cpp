#include<bits/stdc++.h>
using namespace std;
int minOperation(string arr[],int N)
{
    int cntMinOp=0;
    int M=arr[0].size();
    int hash[256][M];
    memset(hash,0,sizeof(hash));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            hash[arr[i][j]][j]++;
    }
    for(int i=0;i<M;i++)
    {
        int Sum=0;
        int Max=0;
        for(int j=0;j<256;j++)
        {
            Sum+=hash[j][i];
            Max=max(hash[j][i],Max);
        }
        cntMinOp+=Sum-Max;
    }
    return cntMinOp;
}
int main()
{
    string arr[] = { "abcd", "bcde", "cdef" };
 
    int N = sizeof(arr) / sizeof(arr[0]);
    // Function call
    cout << minOperation(arr, N) << "\n";
}