#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int main(){
    fast;
    int n,k; cin>>n>>k;
    ll f[n+1];
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=0;
        for(int j=1;j<=k;j++){
            if(i>=j){
            f[i]+=f[i-j]%mod;
            f[i]%=mod;
        }
        }
    }
    cout<<f[n]%mod;
}
