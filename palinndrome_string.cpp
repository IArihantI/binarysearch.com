#include<bits/stdc++.h>
using namespace std;
int binary_to_decimal(int n)
{
    int temp=n;
    int c=0;
    int sum=0;
    while(temp!=0)
    {
        sum=sum+temp%10*pow(2,c++);
        temp/=10;
    }
    return sum;
}
void decimal_to_octal(int n)
{
    int temp=n;
    int sum=0,rem,b=1;
    while(temp!=0)
    {
        rem=temp%8;
        sum=sum+rem*b;
        b*=10;
        temp=temp/8;
    }
    cout<<sum<<endl;
}
int main()
{
    int x;
    cin>>x;
    int n=binary_to_decimal(x);
    decimal_to_octal(n);
}