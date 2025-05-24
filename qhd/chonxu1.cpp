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
	sort(a,a+n);
	f[0] = 1;
	for(int i = a[0] ; i <= s ; i++){
		for(int j = 0; j < n ; j++){
			if(i - a[j] >= 0){
				f[i] += (f[i - a[j]]) % mod;
			}
		}
	}
	cout<<f[s] % mod;
}