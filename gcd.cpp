#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll binpow(ll a, ll b){
	if(b==1) return a;
	ll x=binpow(a,b/2);
	if(b%2==0){
		ll k=x%mod;
		return (k*k) %mod;
	}
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    string s;
    ll n,res=0;
    cin>>s;
    cin>>n;
    for(int i=0;i<s.size()-1;i++){
    	res+=res*10+(s[i]-'0');
    	res%=n;
	}
	ll k=__gcd(n,res);
	cout<<k;
}
