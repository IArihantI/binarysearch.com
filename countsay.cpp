#include<iostream>
#include<string>
using namespace std;
string countAndSay(int n) {
        
        if(n==1)
            return "1";
        string ans="1";
        int count;
        char character;
        while(n>1){
            string ret="";
            count=1;
            for(int j=0;j<ans.length();j++)
            {
                if(j+1<ans.length() && ans[j+1]==ans[j])
                    count++;
                else{
                    ret+=to_string(count)+ans[j];
                    count=1;
                }
            }
            ans=ret;
            n--;
        }
        return ans;
    }
    int main()
    {      
        int n;
        cout<<"Enter a no:- ";
        cin>>n;
        cout<<countAndSay(n)<<endl;
        return 0;
    }
   /*
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
   */