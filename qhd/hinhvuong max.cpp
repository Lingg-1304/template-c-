#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define II pair<int,int>
#define fi first
#define se second
int mod=1e9+7;
int a[505][505];
int dp[505][505];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(a[i][j]==1){
    			dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			}
			
		}
	}
	int maxc=-1e9;
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(dp[i][j]>maxc) maxc=dp[i][j];
		}
	}
	cout<<maxc<<' '<<maxc;
}
