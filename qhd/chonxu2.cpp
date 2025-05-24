#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = 1e9 + 7;
const int maxs = 1e6 + 5;
int n , a[105] , s;
ll f[maxs];
int main(){
	cin >> n >> s;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++){
		f[a[i]]++;
		for(int j = a[i] + 1 ; j <= s ; j++){
			f[j] += (f[j - a[i]]) % mod;
		}
	}
	cout<<f[s] % mod;
}