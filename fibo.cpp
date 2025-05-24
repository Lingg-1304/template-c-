#include <bits/stdc++.h>
#define ff first
#define ss second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9 + 7;
struct matran{
	ll f[2][2];
};
matran nhan(matran a, matran b){
	matran c;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			c.f[i][j] = 0;
			for(int k=0;k<2;k++){
				c.f[i][j] += a.f[i][k]%mod * b.f[k][j]%mod;
				c.f[i][j] %=mod;
			}
		}
	}
	return c;
}
matran power(matran n, ll k){
	if(k == 1) return n;
	matran x = power(n,k/2);
	if(k % 2 == 0) return nhan(x,x);
	else return nhan(n,nhan(x,x));
}
int main(){
    fast;
    ll n; cin>>n;
    matran a;
    a.f[0][0] = a.f[1][0] = a.f[0][1] = 1;
    a.f[1][1] = 0;
    matran res = power(a,n);
    cout<<res.f[1][0];
}
