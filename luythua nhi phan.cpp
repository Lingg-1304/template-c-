#include <bits/stdc++.h>
#define ff first
#define ss second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9 + 7;
ll power(ll n, ll k){
	if(k==0) return 1;
	ll x = power(n,k/2);
	if(k % 2 == 0) return (x%mod * x%mod)%mod;
	else return n%mod * (x%mod * x%mod)%mod;
}
int main(){
    fast;
    ll n; cin>>n;
    ll kq =1ll * power(2,n)/2;
    cout<<kq;
}
