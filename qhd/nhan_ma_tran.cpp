#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 111539786;
struct matran
{
	ll m[2][2];
};
matran nhan(matran a , matran b){
	matran c;
	c.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0];
	c.m[0][1] = a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1];
	c.m[1][0] = a.m[0][1] * b.m[0][0] + a.m[1][1] * b.m[1][0];
	c.m[1][1] = a.m[0][1] * b.m[0][1] + a.m[1][1] * b.m[1][1];
	c.m[0][0] %= mod;
	c.m[0][1] %= mod;
	c.m[1][0] %= mod;
	c.m[1][1] %= mod;
	return c;
} 
matran powmod(matran a , ll n){
	if(n == 1) return a;
	if(n % 2 == 0){
		matran k = powmod(a,n/2);
		return nhan(k,k);
	}
	else{
		matran k = powmod(a,n/2);
		return nhan(nhan(k,k) * a);
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		ll x; cin>>x;
		matran k;
		k.m[0][0] = 1 , k.m[0][1] = 1;
		k.m[1][0] = 1 , k.m[1][1] = 0;
		
	}
}