#include<bits/stdc++.h>
using ll = long long;
const int maxn = 1e6 + 5;
int mod = 1e9 + 7;
using namespace std;
int n,m;
string s,t;
ll hasht , f[maxn] , p[maxn];
ll getHash(int l , int r){
	return (f[r] - f[l-1] * p[r-l+1] + 1ll * mod * mod) % mod;
}
int main(){
	cin >> s >> t;
	n = s.size() , m = t.size();
	s = '@' + s;
	t = '@' + t;
	for(int i = 1 ; i <= m ; i++) hasht = (hasht*31 + t[i] - 'a' + 1) % mod;
	for(int i = 1 ; i <= n ; i++){
		f[i] = f[i-1] * 31 + s[i] - 'a' + 1;
		f[i] %= mod;
	}
	//pow base
	p[0] = 1;
	for(int i = 1 ; i <= m ; i++) p[i] = p[i-1] * 31 % mod;

	//xuly
	for(int i = 1 ; i <= n - m + 1 ; i++){
		if(hasht == getHash(i,i+m-1)) cout<<i<<' '; 
	}
}