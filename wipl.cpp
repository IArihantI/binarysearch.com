#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> a;
int n,k;
ll solve(ll S){
	ll i,j;
	bool dp[n+1][S+1];
	for(i=0;i<=n;i++)
		dp[i][0]=true;
	for(i=1;i<=S;i++)
		dp[0][i]=false;
	for(i=1;i<=n;i++){
		for(j=1;j<=S;j++){
			dp[i][j]=dp[i-1][j];
			if(a[i-1]<=j)
				dp[i][j] = dp[i][j] | dp[i-1][j-a[i-1]];
		}
	}
	ll c=-1,middle=0,tarsum=a[0];
	ll x=INT_MAX,y=INT_MAX;
	for(i=1;i<n;i++){
		middle=INT_MAX;
		tarsum+=a[i];
		for(j=tarsum/2;j>0;j--){
			if(dp[i+1][j]==true){
				middle=tarsum-2*j;
				break;
			}
		}
		x=(tarsum+middle)/2;
		y=x-middle;
		// cout<<"("<<x<<" "<<y<<")";
		if(min(x,y)>=k){
			c=i+1;
			break;
		}
	}
	return c;
}

int main(){
int t;
cin >> t;
while(t--)
	{
		cin>>n>>k;
		a.clear();
		ll i,sum=0;
		for(i=0;i<n;i++){
			ll x;cin>>x;
			a.push_back(x);
			sum+=x;
		}
        cout<<endl;
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		if(sum<(2*k)){
			cout<<"-1\n";
			continue;
		}
		sort(a.begin(),a.end(),greater<ll>());
		if(a[1]>=k){
			cout<<"2\n";
			continue;
		}
		if(a[0]>=k){
			ll cnt=1; sum=0;
			for(i=1;i<n;i++){
				if(sum<k){
					sum+=a[i];
					cnt++;
				}
				if(sum>=k)break;
			}
			if(sum>=k)
				cout<<cnt<<"\n";
			else cout<<"-1\n";
			continue;
		}
		sum=0;
		for(i=0;i<n;i++){
			if(sum<2*k)
				sum+=a[i];
			if(sum>=2*k)break;
		}
		ll c=solve(sum);
		cout<<c<<"\n";
	}
}