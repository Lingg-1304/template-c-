#include<bits/stdc++.h>
using namespace std;
int main(){
//    freopen("hi.inp","r",stdin);
//    freopen("hi.out","w",stdout);
    int n,k;
    cin>>n;
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=sqrt(n);i++){
    	for(int j=i*i;j<=n;j+=i){
    		dp[j]=1;
		}
	}
	for(int i=0;i<=n;i++){
		if(dp[i]==0) cout<<i<<" ";
	}
    return 0;
}
