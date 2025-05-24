#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
ll f[1001][1001];
int main(){
    fast;
    int n; cin>>n;
    f[0][1]=1;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		char k; cin>>k;
    		if(k == '.'){
    			f[i][j] = f[i][j-1]%mod + f[i-1][j]%mod;
    			f[i][j]%=mod;
			}
			else f[i][j]=0;
		}
	}
	cout<<f[n][n];
}
