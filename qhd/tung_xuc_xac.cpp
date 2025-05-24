#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[1000005];
int mod = 1e9 + 7;
int main(){
	int n; cin >> n;
	dp[1] = 1;

	for(int i = 1 ; i <= 6 ; i++){
		ll sum = 1;
		for(int j = 1 ; j < i ; j++){
			sum += dp[j];
		}
		dp[i] = sum;
	}
	for(int i = 7 ; i <= n ; i++){
		ll sum = 0;
		for(int j = i - 6 ; j < i ; j++){
			sum += dp[j];
			sum %= mod;
		}
		dp[i] = sum % mod;
	}
	cout<<dp[n];
}