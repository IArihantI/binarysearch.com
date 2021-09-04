#include<bits/stdc++.h>
using namespace std;
const string EMPTY = "";
 
const string X[] = { EMPTY, "one ", "two ", "three ", "four ", "five ",
                "six ", "seven ", "eight ", "nine ", "ten ", "eleven ",
                "twelve ", "thirteen ", "fourteen ", "fifteen ",
                "sixteen ", "seventeen ", "eighteen ", "nineteen " };
 
const string Y[] = { EMPTY, EMPTY, "twenty ", "thirty ", "forty ", "fifty ",
                "sixty ", "seventy ", "eighty ", "ninety " };
 
string convertToDigit(int n)
{
    if (n == 0) {
        return EMPTY;
    }
 
    if (n > 19) {
        return Y[n / 10] + X[n % 10];
    }
    else {
        return X[n];
    }
}
int count_vowels(string s)
{
    int l=s.size(),v=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        v++;
    }
    return v;
}
int main()
{
    int n,d=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==100)
            d+=2;
        else
        {
            string s=convertToDigit(arr[i]);
            d+=count_vowels(s);
        }
    }
    if(d>100)
        cout<<"greater 100"<<endl;
    else
    {   int p=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
            m[arr[i]]=1;
        for(int i=0;i<n;i++)
        {
            if(m[d-arr[i]]==1)
            p++;
        }
        cout<<p;
    }
    return 0;
}